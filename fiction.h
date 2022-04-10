// file fiction.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef FICTION_H
#define FICTION_H

#include <string>
#include "book.h"

//----------------------------------------------------------------------------
// Fiction class: Creates and returns fiction objects
// corresponding to an input character key.
// 
// Assumptions and implementation:
//     - Assumes that information in the input file is correctly formatted.
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Fiction : public Book {

public:

   //-------------------------------------------------------------------------
   // Fiction()
   // Constructor
   Fiction();

   //-------------------------------------------------------------------------
   // ~Fiction()
   // destructor
   // destroys Fiction object
   ~Fiction();

   //-------------------------------------------------------------------------
   // create()
   // creates and returns a Fiction object
   virtual LibraryItem* create();

   //-------------------------------------------------------------------------
   // setData()
   // sets data members of Fiction object
   virtual void setData(ifstream& bookInfoFile);

   //------------------------------------------------------------------------
   // setCommandData()
   // sets data members of temp Fiction object for Command
   // Command classes call this method
   virtual void setCommandData(ifstream& bookInfoFile);

   //-------------------------------------------------------------------------
   // display()
   // displays Fiction object
   virtual void display(ostream &out) const;

   //-----------------------------------------------------------------------
   // displayHeader()
   // prints header for Fiction object output
   virtual void displayHeader(ostream &out) const;

   //-------------------------------------------------------------------------
   // displaySpecific()
   // display certain variables in Fiction object
   virtual void displaySpecific(ostream &out) const;

   //-------------------------------------------------------------------------
   // patronHistoryDisplay()
   // display fiction object
   // used when displaying the patron history
   virtual void patronHistoryDisplay(ostream &out) const;

   //-------------------------------------------------------------------------
   // increaseCount()
   // increases count of copiesAvailable
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
   // operator>=
   // checks if calling object is bigger/equal than other object
   virtual bool operator>=(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // setAuthor()
   // sets author of Fiction object
   void setAuthor(string author);

private:

   string author;   // author of book

};

#endif