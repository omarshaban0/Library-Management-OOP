// file libraryItemFactory.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "libraryItemFactory.h"
#include "libraryItem.h"
#include "childrens.h"
#include "fiction.h"
#include "periodical.h"

//-----------------------------------------------------------------------
// libraryItemFactory()
// Initializes the contents of libraryItemTable with nullptr or pointers
// requires the method hash()
// to libraryItem objects.
LibraryItemFactory::LibraryItemFactory() {
   for (int i = 0; i < 52; i++) {
      libraryItemTable[i] = nullptr;
   }
   libraryItemTable[hash('F')] = new Fiction();
   libraryItemTable[hash('C')] = new Childrens();
   libraryItemTable[hash('P')] = new Periodical();
}

//-----------------------------------------------------------------------
// ~libraryItemFactory()
// Deallocates all libraryItem object pointers in libraryItemTable. 
LibraryItemFactory::~LibraryItemFactory() {
   for (int i = 0; i < 52; i++) {
      delete libraryItemTable[i];
      libraryItemTable[i] = nullptr;
   }
}

//-----------------------------------------------------------------------
// createItem()
// return a new libraryItem object that corresponds to 'key' 
// else returns nullptr
LibraryItem * LibraryItemFactory::createItem(char key) const {
   int subscript = hash(key); // would do error checking

   // checks if object does not exist in factory
   if (subscript == -1 || libraryItemTable[subscript] == nullptr) {
      return nullptr;
   }

   return libraryItemTable[subscript]->create();
}

//-----------------------------------------------------------------------
// hash()
// converts a alphabetical character input into an integer index
int LibraryItemFactory::hash(char type) const {

   // if character is not alphabetical
   if (!isalpha(type)) {
      return -1;
   }

   // get ascii for uppcase character
   char upperCaseChar = toupper(type);
   return (int(upperCaseChar) - 65);
}