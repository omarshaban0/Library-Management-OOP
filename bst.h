// file bst.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef BST_H
#define BST_H

class LibraryItem;

#include <iostream>
#include <algorithm>

using namespace std;

//----------------------------------------------------------------------------
// class BST
// ADT Binary Search Tree: node-based binary tree data structure which has
// the following properties: (1) The left subtree of a node contains only
// nodes with keys lesser than the node’s key (2) The right subtree of a
// node contains only nodes with keys greater than the node’s key
// (3) The left and right subtree each must also be a binary search tree.
//          
// Implementation and assumptions:  
//   -- The tree class is not tied to any particular type of data beyond
//      libraryItem as containers don’t know anything the data they hold.
//   -- Must use a tree node which holds a libraryItem* for the data
//      (along with the left and right pointers).
//   -- Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Bst {

  //--------------------------------------------------------------------------
  // operator<< 
  // output operator for class BST
  // requires the method inorderHelper()
  // prints the BST In-Order and requires existing BST object
  friend ostream & operator<<(ostream &, const Bst&);

public:

  //--------------------------------------------------------------------------
  // Constructor
  Bst();

  //--------------------------------------------------------------------------
  // Destructor
  // destroys BST object
  // requires the method makeEmpty()
  ~Bst();

  //--------------------------------------------------------------------------
  // makeEmpty
  // deletes all memory
  // requires the method makeEmptyHelper()
  // output should be the root set to nullptr
  void makeEmpty();

  //--------------------------------------------------------------------------
  // isEmpty
  // checks if BinTree is empty by checking if root is null
  // returns whether or not it is
  bool isEmpty() const;

  //--------------------------------------------------------------------------
  // insert 
  // insert node into BinTree object
  // requires the method insertHelper()
  // assume BinTree is a binary search tree
  bool insert(LibraryItem* data);

  //--------------------------------------------------------------------------
  // retrieve 
  // retrieve a libraryItem* of a given object in the tree
  // requires the method retrieveHelper()
  // assume BST is a binary search tree
  // return whether found
  bool retrieve (const LibraryItem &target, LibraryItem* &retrieved);

private:

  struct Node{
    LibraryItem* data;   // pointer to data object
    Node* left;          // left subtree pointer
    Node* right;         // right subtree pointer
  };
  Node* root;            // root of the tree

  //--------------------------------------------------------------------------
  // inorderHelper
  // recursive helper for operator<<()
  void inorderHelper(Node* current, ostream &out) const;

  //--------------------------------------------------------------------------
  // makeEmptyHelper
  // recursive helper for makeEmpty()
  void makeEmptyHelper(Node* &current);

  //--------------------------------------------------------------------------
  // insertHelper
  // recursive helper for insert()
  void insertHelper(Node* &current, LibraryItem* data, bool &flag);

  //--------------------------------------------------------------------------
  // retrieveHelper
  // recursive helper for retrieve()
  void retrieveHelper(const Node* current, const LibraryItem &target, 
                                LibraryItem* &retrieved, bool &found) const;
   
};

#endif