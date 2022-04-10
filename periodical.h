// file periodical.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef PERIODICAL_H
#define PERIODICAL_H

#include <string>
#include "book.h"

//----------------------------------------------------------------------------
// Periodical class: Creates and returns periodical objects
// corresponding to an input character key.
// 
// Assumptions and implementation:
//     - Assumes that information in the input file is correctly formatted.
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------
 
class Periodical : public Book {

public:

   //-------------------------------------------------------------------------
   // Periodical()
   // Constructor
   Periodical();

   //-------------------------------------------------------------------------
   // ~Periodical()
   // destructor
   // destroys Periodical object
   virtual ~Periodical();

   //-------------------------------------------------------------------------
   // create()
   // creates and returns a Periodical object
   virtual LibraryItem* create();

   //-------------------------------------------------------------------------
   // setData()
   // sets data members of Periodical object
   virtual void setData(ifstream& bookInfoFile);

   //-------------------------------------------------------------------------
   // setCommandData()
   // sets data members of temp Periodical object for Command
   // command classes call this method
   virtual void setCommandData(ifstream& bookInfoFile);

   //-------------------------------------------------------------------------
   // display()
   // displays Periodical object
   virtual void display(ostream &out) const;

   //-------------------------------------------------------------------------
   // displayHeader()
   // displays header for Periodical object
   virtual void displayHeader(ostream &out) const;

   //-------------------------------------------------------------------------
   // displaySpecific()
   // display certain variables in Periodical object
   virtual void displaySpecific(ostream &out) const;

   //-------------------------------------------------------------------------
   // patronHistoryDisplay()
   // display periodical object
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

   //------------------------------------------------------------------------
   // operator<=
   // checks if calling object is smaller/equal than other object
   virtual bool operator<=(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // operator>=
   // checks if calling object is bigger/equal than other object
   virtual bool operator>=(const LibraryItem& other) const;

   //-------------------------------------------------------------------------
   // setMonth()
   // sets month of Periodical object
   void setMonth(int month);

private:
  
   int month;    // month book was made

};

#endif
