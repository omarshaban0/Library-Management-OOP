// file treetable.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef TREETABLE_H
#define TREETABLE_H

class LibraryItem;

#include "bst.h"
#include <ctype.h>
#include <iostream>
#include <stdio.h>

using namespace std;

//----------------------------------------------------------------------------
// TreeTable class: stores BST objects.
//
// Assumptions and implementation:
//     - Assumes there is an implemented BST class
//     - Size is limited
//     - There is no remove method
//     - The tree table stores based off LibraryItem type
//       (ex: C (childrens) or F (fiction))
//     - There can only be 1 BST per book type. The tree table can't store
//       more than one LibraryItem of same type.
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class TreeTable {

public:

   //-----------------------------------------------------------------------
   // treeTable()
   // Initializes the contents of treeTable with nullptr or pointers to
   // bst objects.
   TreeTable();

   //-----------------------------------------------------------------------
   // ~treeTable()
   // Deallocates all bst object pointers in treeTable.
   ~TreeTable();

   //-----------------------------------------------------------------------
   // insert();
   // Insert a LibraryItem object into the corresponding BST
   // Requires the methods hash() and insert() from BST
   // Returns false if the bst object was already in the table, or
   // hashing fails.
   bool insert(char type, LibraryItem *libItem);

   //-----------------------------------------------------------------------
   // retrieve();
   // Requires the methods hash() and retrieve() from BST
   // retrieves LibraryItem object into the corresponding BST
   void retrieve(const LibraryItem &target, LibraryItem *&retrieved,
                 const char bookType);

   //-----------------------------------------------------------------------
   // display()
   // requires the method isEmpty() from BST
   // displays all LibraryItems stored in the tree table
   void display() const;

private:

   //-----------------------------------------------------------------------
   // hash()
   // Hasher function that converts a character input into an integer index.
   int hash(char type) const;
  
   Bst hashTable[52]; // Array of BST's

};

#endif