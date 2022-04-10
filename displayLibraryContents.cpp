// file displayLibraryContents.cpp
// Author: Dani Shaykho and Omar Naji Shaban

#include "displayLibraryContents.h"

//-----------------------------------------------------------------------
// DisplayLibraryContents()
// constructor
DisplayLibraryContents::DisplayLibraryContents() {}

//-----------------------------------------------------------------------
// destructor
// destroys DisplayLibraryContents object
DisplayLibraryContents::~DisplayLibraryContents() {}

//-----------------------------------------------------------------------
// create()
// constructs an uninitialized DisplayLibraryContents object and
// returns a pointer to the object
Command* DisplayLibraryContents::create() {
   return new DisplayLibraryContents();
}

//-----------------------------------------------------------------------
// execute()
// Requires displayLibrary() from Library
// displays library contents, then returns false
bool DisplayLibraryContents::execute() {
   library->displayLibrary();

   // false so executeCommands() (in library) 
   // deletes displayLibContents command
   return false;
}

//----------------------------------------------------------------------------
// setData()
// sets data members of DisplayLibraryContents object
bool DisplayLibraryContents::setData(ifstream& commandInfoFile) {
   return true;
}

//----------------------------------------------------------------------------
// display()
// displays DisplayLibraryContents information
void DisplayLibraryContents::display(ostream& out) const {}