// file treetable.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "treeTable.h"
#include "libraryItem.h"

//-----------------------------------------------------------------------
// treeTable()
// Initializes the contents of treeTable with nullptr
TreeTable::TreeTable() {}

//-----------------------------------------------------------------------
// ~treeTable()
// Destructor
TreeTable::~TreeTable() {}

//-----------------------------------------------------------------------
// insert()
// Insert a LibraryItem object into the corresponding BST
// Requires the methods hash() and insert() from BST
// Returns false if the bst object was already in the table, or 
// hashing fails. 
bool TreeTable::insert(char type, LibraryItem* libItem) {
   int key = hash(type);

   // if hash is invalid or key does not already have a value
   if (key == -1) {
      return false;
   }

   bool success;
   success = hashTable[key].insert(libItem);

   // delete libItem if it's a duplicate
   if (!success) {
      delete libItem;
      libItem = nullptr;
   }

   return success;
}

//-----------------------------------------------------------------------
// retrieve()
// Requires the methods hash() and retrieve() from BST
// retrieves LibraryItem object into the corresponding BST
void TreeTable::retrieve(const LibraryItem& target,
   LibraryItem* &retrieved,
   const char bookType) {

   hashTable[hash(bookType)].retrieve(target, retrieved);
}

//-----------------------------------------------------------------------
// display()
// requires the method isEmpty() from BST
// displays all LibraryItems stored in the tree table
void TreeTable::display() const {
   for (int i = 0; i < 52; i++) {
      cout << hashTable[i];
      if (!hashTable[i].isEmpty()) {
         cout << endl;
      }
   }
}

//-----------------------------------------------------------------------
// hash()
// Hasher function that converts a character input into an integer index.
int TreeTable::hash(char type) const {

   // if character is not alphabetical
   if (!isalpha(type)) {
      return -1;
   }

   // get ascii for uppcase character
   char upperCaseChar = toupper(type);
   return (int(upperCaseChar) - 65);
}