// file libraryItem.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "libraryItem.h"

//----------------------------------------------------------------------------
// ~LibraryItem()
// destructor 
// destroys LibraryItem object
LibraryItem::~LibraryItem() {}

//----------------------------------------------------------------------------
// decreaseCount()
// decreases count of LibraryItem
bool LibraryItem::decreaseCount() {
  if(copiesAvailable != 0) {
    copiesAvailable--;
    return true;
  }
  return false;
}