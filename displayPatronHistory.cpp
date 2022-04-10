// file displayLibraryContents.cpp
// Author: Dani Shaykho and Omar Naji Shaban

#include "library.h"
#include "displayPatronHistory.h"
#include "patron.h"

//-----------------------------------------------------------------------
// DisplayPatronHistory()
// constructor
DisplayPatronHistory::DisplayPatronHistory() {}

//-----------------------------------------------------------------------
// ~DisplayPatronHistory()
// destructor
// destroys DisplayPatronHistory object
DisplayPatronHistory::~DisplayPatronHistory() {}

//-----------------------------------------------------------------------
// create()
// returns a DisplayPatronHistory object
Command * DisplayPatronHistory::create() {
   return new DisplayPatronHistory();
}

//-----------------------------------------------------------------------
// execute()
// Requires displayHistory() from Patron
// displays patron history, then returns false
bool DisplayPatronHistory::execute() {
   patron->displayHistory(cout);

   // false so executeCommands() (in library) 
   // deletes displayLibContents command
   return false;
}

//---------------------------------------------------------------------------
// setData()
// requires the method retreivePatron() from library class
// sets data members of DisplayLibraryContents object
bool DisplayPatronHistory::setData(ifstream& commandInfoFile) {
   int patronID; // ID of the patron

   commandInfoFile >> patronID;

   // get the Patron
   patron = nullptr;
   library->retrievePatron(patronID, patron);

   // if patron doesn't exist, skip line
   if (patron == nullptr) {
      cout << "HISTORY ERROR: There is no patron with ID " <<
         patronID << "." << endl;
      cout << endl;
      return false;
   }
   return true;
}

//----------------------------------------------------------------------------
// display()
// displays DisplayPatronHistory information
void DisplayPatronHistory::display(ostream& out) const {
   cout << "Display Patron History Command" << endl;
}