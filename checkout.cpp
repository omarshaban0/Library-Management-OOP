// file checkout.h
// Author: Dani Shaykho and Omar Naji Shaban

#include "checkout.h"

//-----------------------------------------------------------------------
// Checkout()
// constructor
Checkout::Checkout() {
   bookType = 'B';
   bookFormat = 'H';
   commandType = "CheckOut";
}

//-----------------------------------------------------------------------
// ~Checkout()
// destructor
// destroys Checkout object
Checkout::~Checkout() {}

//-----------------------------------------------------------------------
// create()
// return a Checkout object
Command* Checkout::create() {
   return new Checkout();
}

//-----------------------------------------------------------------------
// execute()
// requires methods from Patron: getFirstName(), getLastName(),
// and addCommand()
// requires methods from Library: decreaseCount() and displaySpecific()
// checksout book and adds command to patron history
bool Checkout::execute() {

   // decreases count if true, else display error message
   if (libItem->decreaseCount() == false) {
      cout << "CHECKOUT ERROR: " << patron->getFirstName() << " ";
      cout << patron->getLastName() << " tried to check out '";
      libItem->displaySpecific(cout);
      cout << "' - No Available Copies." << endl;
      cout << endl;
      return false;
   }

   // update patron's history
   patron->addCommand(this);

   return true;
}

//----------------------------------------------------------------------------
// setData()
// requires the methods from Patron: getFirstName() and getLastName()
// requires the methods from LibraryItem: setCommandData(), 
// displaySpecific()
// requires the methods from Library: retrievePatron(), createLibItem(),
// and retrieveLibItem()
// sets data members of Checkout object
bool Checkout::setData(ifstream& commandInfoFile) {
   int patronID;
   LibraryItem * tempItem; // used to find a matching LibraryItem

   commandInfoFile >> patronID;

   // get the Patron
   patron = nullptr;
   library->retrievePatron(patronID, patron);

   // if patron doesn't exist, skip line
   if(patron == nullptr) {
      cout << "CHECKOUT ERROR: There is no patron with ID " <<
         patronID << "." << endl;
      cout << endl;
      return false;
   }

   commandInfoFile >> bookType;

   tempItem = library->createLibItem(bookType);

   // if LibraryItem type doesn't exist, skip line
   if(tempItem == nullptr) {
      cout << "CHECKOUT ERROR: " << bookType <<
         " is not a valid LibItem type." << endl;
      cout << endl;
      return false;
   }

   commandInfoFile >> this -> bookFormat;

   if(bookFormat != 'H') {
      cout << "CHECKOUT ERROR: " << bookFormat <<
         " is not a valid LibItem format." << endl;
      cout << endl;

      // delete the temporary Library Item 
      delete tempItem;
      tempItem = nullptr;

      return false;
   }
   tempItem->setCommandData(commandInfoFile);

   // get LibraryItem
   libItem = nullptr;
   library->retrieveLibItem(*tempItem, libItem, bookType);

   // if LibraryItem doesn't exist in Library, skip line
   if(libItem == nullptr) {
      cout << "CHECKOUT ERROR: " << patron->getFirstName() << " ";
      cout << patron->getLastName() << " tried to check out '";
      tempItem->displaySpecific(cout);
      cout << "' - Book doesn't exist." << endl;
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
// displays Checkout information
void Checkout::display(ostream & out) const {
   out << setw(15) << left << "CheckOut";
   libItem->patronHistoryDisplay(out);
}