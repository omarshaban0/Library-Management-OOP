// file childrens.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef CHILDRENS_H
#define CHILDRENS_H

#include <string>
#include "book.h"

//----------------------------------------------------------------------------
// Childrens class: Creates and returns Childrens objects
// corresponding to an input character key.
// 
// Assumptions and implementation:
//     - Assumes that information in the input file is correctly formatted.
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Childrens : public Book {

public:

   //-------------------------------------------------------------------------
   // Childrens()
   // Constructor
   Childrens();

   //-------------------------------------------------------------------------
   // ~Childrens()
   // destructor 
   // destroys Childrens object
   ~Childrens();

   //-------------------------------------------------------------------------
   // create()
   // creates and returns a Childrens object
   virtual LibraryItem* create();

   //-------------------------------------------------------------------------
   // setData()
   // sets data members of Childrens object
   virtual void setData(ifstream& bookInfoFile);

   //-------------------------------------------------------------------------
   // setCommandData()
   // sets data members of temp Childrens object for Command
   // command classes call this method
   virtual void setCommandData(ifstream& bookInfoFile);

   //-------------------------------------------------------------------------
   // display()
   // displays Childrens object
   virtual void display(ostream &out) const;

   //-------------------------------------------------------------------------
   // displayHeader()
   // displays header for Childrens object
   virtual void displayHeader(ostream &out) const;

   //-------------------------------------------------------------------------
   // displaySpecific()
   // display certain variables in Childrens object
   virtual void displaySpecific(ostream &out) const;

   //-------------------------------------------------------------------------
   // patronHistoryDisplay()
   // display Childrens object
   // used when displaying the patron history
   virtual void patronHistoryDisplay(ostream &out) const;

   //-------------------------------------------------------------------------
   // increaseCount()
   // increases count of availCopies
   virtual bool increaseCount();

   //-------------------------------------------------------------------------
   // operator>
   // checks if calling object is bigger than other object
   virtual bool operator>(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // operator<
   // checks if calling object is smaller than other object
   virtual bool operator<(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // operator==
   // checks if two objects are equal
   virtual bool operator==(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // operator<=
   // checks if calling object is smaller/equal than other object
   virtual bool operator<=(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // operator<=
   // checks if calling object is bigger/equal than other object
   virtual bool operator>=(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // setAuthor()
   // sets author of Childrens object
   void setAuthor(string author);

private:

   string author;    // author of book

};

#endif