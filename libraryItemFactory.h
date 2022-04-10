// file libraryItemFactory.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef LIBRARYITEMFACTORY_H
#define LIBRARYITEMFACTORY_H

class LibraryItem;

#include <iostream>

using namespace std;

//----------------------------------------------------------------------------
// libraryItemFactory class: Creates and returns libraryItem objects
// corresponding to an input character key.
// 
// Assumptions and implementation:
//     - Currently needs the classes Childrens, Periodical, and Fiction
//       to be fully implemented
//     - Currently only returns Childrens, Periodical, and Fiction objects
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class LibraryItemFactory {

public:
  
   //-----------------------------------------------------------------------
   // libraryItemFactory()
   // Initializes the contents of libraryItemTable with nullptr or pointers
   // requires the method hash()
   // to libraryItem objects.
   LibraryItemFactory();
  
   //-----------------------------------------------------------------------
   // ~libraryItemFactory()
   // Deallocates all libraryItem object pointers in libraryItemTable. 
   ~LibraryItemFactory();
  
   //-----------------------------------------------------------------------
   // createItem()
   // return a new libraryItem object that corresponds to 'key' 
   // else returns nullptr
   LibraryItem* createItem(char key) const;

private:

   //-----------------------------------------------------------------------
   // Array of libraryItem pointers.
   // Contains each derived class object of libraryItem that is called to
   // create a new libraryItem object. 
   LibraryItem* libraryItemTable[52];
  
   //-----------------------------------------------------------------------
   // hash()
   // converts a alphabetical character input into an integer index
   int hash(char key) const;

};

#endif