// file command.cpp
// Author: Dani Shaykho and Omar Naji Shaban

#include "command.h"
#include "library.h"
#include "libraryItem.h"

//-----------------------------------------------------------------------
// destructor
// destroys Command object
Command::~Command() {}

//----------------------------------------------------------------------------
// setLibrary()
// sets library
void Command::setLibrary(Library* libraryPtr) {
   this -> library = libraryPtr;
}

//----------------------------------------------------------------------------
// getCommandType()
// returns command type 
string Command::getCommandType() const {
   return commandType;
}

//----------------------------------------------------------------------------
// getLibItem()
// returns library item pointer
LibraryItem* Command::getLibItem() const {
   return libItem;
}