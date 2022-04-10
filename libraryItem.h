// file libraryItem.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//----------------------------------------------------------------------------
// LibraryItem class: Super class (interface for Library Items that inherit
// this class).
// 
// Assumptions and implementation:
//     - Assume that a "LibraryItem" object will not be created
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class LibraryItem {

public:

   //-------------------------------------------------------------------------
   // ~LibraryItem()
   // destructor 
   // destroys LibraryItem object
   virtual ~LibraryItem();

   //------------------------------------------------------------------------
   // create()
   // creates and returns a LibraryItem object
   virtual LibraryItem* create() = 0;

   //-------------------------------------------------------------------------
   // setData()
   // sets data members of LibraryItem object
   virtual void setData(ifstream& bookInfoFile) = 0;

   //-------------------------------------------------------------------------
   // setCommandData()
   // sets data members of temp LibraryItem object for Command
   // command classes call this method
   virtual void setCommandData(ifstream& bookInfoFile) = 0;

   //-------------------------------------------------------------------------
   // display()
   // display LibraryItem object
   virtual void display(ostream &out) const = 0;

   //-------------------------------------------------------------------------
   // displayHeader()
   // displays header for LibraryItem object
   virtual void displayHeader(ostream &out) const = 0;

   //-------------------------------------------------------------------------
   // displaySpecific()
   // display certain variables in LibraryItem object
   virtual void displaySpecific(ostream &out) const = 0;

   //-------------------------------------------------------------------------
   // patronHistoryDisplay()
   // display LibraryItem object
   // used when displaying the patron history
   virtual void patronHistoryDisplay(ostream &out) const = 0;

   //-------------------------------------------------------------------------
   // increaseCount()
   // increases count of copiesAvailable
   virtual bool increaseCount() = 0;

   //-------------------------------------------------------------------------
   // operator>
   // checks if calling object is bigger than other object
   virtual bool operator>(const LibraryItem& other) const = 0;

   //-------------------------------------------------------------------------
   // operator<
   // checks if calling object is smaller than other object
   virtual bool operator<(const LibraryItem& other) const = 0;

   //-------------------------------------------------------------------------
   // operator==
   // checks if two objects are equal
   virtual bool operator==(const LibraryItem& other) const = 0;

   //-------------------------------------------------------------------------
   // operator<=
   // checks if calling object is smaller/equal than other object
   virtual bool operator<=(const LibraryItem& other) const = 0;

   //-------------------------------------------------------------------------
   // operator>=
   // checks if calling object is bigger/equal than other object
   virtual bool operator>=(const LibraryItem& other) const = 0;

   //-------------------------------------------------------------------------
   // decreaseCount()
   // decreases count of LibraryItem
   bool decreaseCount();

protected:

   int copiesAvailable;   // number of copies available

};

#endif