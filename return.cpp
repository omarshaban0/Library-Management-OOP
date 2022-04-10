// file return.cpp
// Author: Dani Shaykho and Omar Naji Shaban

#include "return.h"

//-----------------------------------------------------------------------
// Return()
// constructor
Return::Return() {
   this -> bookType = 'B';
   this -> bookFormat = 'H';
   this -> commandType = "Return";
}

//-----------------------------------------------------------------------
// ~Return()
// destructor
Return::~Return() {}

//-----------------------------------------------------------------------
// create()
// return a Return object
Command* Return::create() {
   return new Return();
}

//-----------------------------------------------------------------------
// execute()
// requires the methods from Patron: patronAllowedToReturn(),
// getFirstName(), getLastName(), and addCommand()
// requires the methods from Library: increaseCount(), displaySpecific()
// returns book and adds command to patron history
bool Return::execute() {

   // increases count if true, else display error message
   if (patron -> patronAllowedToReturn(libItem) == false ||
      libItem -> increaseCount() == false) {
      cout << "RETURN ERROR: " << patron -> getFirstName() << " ";
      cout << patron -> getLastName() << " tried to return '";
      libItem -> displaySpecific(cout);
      cout << "' - Book is not checked out by Patron." << endl;
      cout << endl;
      return false;
   }

   // update patron's history
   patron -> addCommand(this);

   return true;
}

//----------------------------------------------------------------------------
// setData()
// requires the methods from Patron: getFirstName(), getLastName(),
// requires the methods from LibraryItem: setCommandData(), displaySpecific()
// requires the methods from Library:retrievePatron(), createLibItem(),
// and retrieveLibItem()
// sets data members of Return object
bool Return::setData(ifstream& commandInfoFile) {
   int patronID;
   LibraryItem* tempItem; // used to find a matching LibraryItem

   commandInfoFile >> patronID;

   // get the Patron
   patron = nullptr;
   library -> retrievePatron(patronID, patron);

   // if patron doesn't exist, skip line
   if (patron == nullptr) {
      cout << "RETURN ERROR: There is no patron with ID " << patronID <<
         "." << endl;
      cout << endl;
      return false;
   }

   commandInfoFile >> this->bookType;
   tempItem = library -> createLibItem(bookType);

   // if LibraryItem type doesn't exist, skip line
   if (tempItem == nullptr) {
      cout << "RETURN ERROR: " << bookType <<
         " is not a valid LibItem type." << endl;
      cout << endl;
      return false;
   }

   commandInfoFile >> this->bookFormat;

   if (bookFormat != 'H') {
      cout << "RETURN ERROR: " << bookFormat <<
         " is not a valid LibItem format." << endl;
      cout << endl;

      // delete the temporary Library Item 
      delete tempItem;
      tempItem = nullptr;

      return false;
   }
   tempItem -> setCommandData(commandInfoFile);

   // get LibraryItem
   libItem = nullptr;
   library -> retrieveLibItem(*tempItem, libItem, bookType);

   // if LibraryItem doesn't exist in Library, skip line
   if (libItem == nullptr) {
      cout << "RETURN ERROR: " << patron -> getFirstName() << " ";
      cout << patron -> getLastName() << " tried to return '";
      tempItem -> displaySpecific(cout);
      cout << "' - Book does't exist." << endl;
      cout << endl;

      // delete the temporary Library Item 
      delete tempItem;
      tempItem = nullptr;

      return false;
   }

   // delete the temporary Library Item 
   delete tempItem;
   tempItem = nullptr;

   return true;
}

//----------------------------------------------------------------------------
// display()
// requires the method patronHistoryDisplay() from LibraryItem
// displays Return information in patron history
void Return::display(ostream& out) const {
   out << setw(15) << left << "Return";
   libItem -> patronHistoryDisplay(out);
}