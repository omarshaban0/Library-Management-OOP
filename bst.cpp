// file bst.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "bst.h"
#include "libraryItem.h"

//----------------------------------------------------------------------------
// operator<< 
// output operator for class BST
// requires the method inorderHelper()
// prints the BST In-Order and requires existing BST object
ostream& operator<<(ostream& out, const Bst& tree) {
   tree.inorderHelper(tree.root, out);
   return out;
}

//----------------------------------------------------------------------------
// inorderHelper
// recursive helper for operator<<()
void Bst::inorderHelper(Node* current, ostream &out) const {
   if(current == nullptr) {
      return;
   }
   if(current == root) {
      current -> data -> displayHeader(out);
   }
   inorderHelper(current->left, out);
   current->data->display(out);
   inorderHelper(current->right, out);
}

//----------------------------------------------------------------------------
// Constructor
Bst::Bst() {
   root = nullptr;
}

//----------------------------------------------------------------------------
// Destructor
// destroys BST object
// requires the method makeEmpty()
Bst::~Bst() {
   makeEmpty();
}

//----------------------------------------------------------------------------
// makeEmpty
// deletes all memory
// requires the method makeEmptyHelper()
// output should be the root set to nullptr
void Bst::makeEmpty() {
   makeEmptyHelper(root);
}

//----------------------------------------------------------------------------
// isEmpty
// checks if BinTree is empty by checking if root is null
// returns whether or not it is
bool Bst::isEmpty() const {
   return root == nullptr;
}

//----------------------------------------------------------------------------
// makeEmptyHelper
// recursive helper for makeEmpty()
void Bst::makeEmptyHelper(Node* &current) {
   if(current == nullptr) {
      return;
   }
   makeEmptyHelper(current->left);
   makeEmptyHelper(current->right);
   delete current->data;
   current->data = nullptr;
   delete current;
   current = nullptr;
}

//----------------------------------------------------------------------------
// insert 
// insert node into BinTree object
// requires the method insertHelper()
// assume BinTree is a binary search tree
bool Bst::insert(LibraryItem* data) {
   bool flag = false;
   insertHelper(root, data, flag);
   return flag;
}

//----------------------------------------------------------------------------
// insertHelper
// recursive helper for insert()
void Bst::insertHelper(Node* &current, LibraryItem* data, bool &flag) {
   if(current == nullptr) {
      current = new Node;
      current->data = data;
      current->left = current -> right = nullptr;
      flag = true;
   } else if (*(current->data) > *data) {       // go to left subtree
      insertHelper(current->left, data, flag);
   } else if (*(current->data) < *data) {       // go to right subtree
      insertHelper(current->right, data, flag);
   }
}

//----------------------------------------------------------------------------
// retrieve 
// retrieve a libraryItem* of a given object in the tree
// requires the method retrieveHelper()
// assume BST is a binary search tree
// return whether found
bool Bst::retrieve(const LibraryItem& target, LibraryItem* &retrieved) {
   bool found = false;
   retrieveHelper(root, target, retrieved, found);
   return found;
}

//----------------------------------------------------------------------------
// retrieveHelper
// recursive helper for retrieve()
void Bst::retrieveHelper(const Node* current, const LibraryItem & target,
                            LibraryItem * & retrieved, bool & found) const {
   if(current == nullptr) {
      return;
   } else if ( *(current->data) == target) {
      found = true;
      retrieved = current->data;
   } else if (*(current->data) > target) {     // go to left subtree
      retrieveHelper(current->left, target, retrieved, found);
   } else {                                    // go to right subtree
      retrieveHelper(current->right, target, retrieved, found);
   }
}