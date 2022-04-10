// file patron.h
// Author: Dani Shaykho and Omar Naji Shaban

#ifndef PATRON_H
#define PATRON_H

class LibItem;

#include "command.h"
#include<iomanip>
#include <string>
#include <vector>

using namespace std;

//--------------------------------------------------------------------------
// Patron class: object to store patron information
// 
// Assumptions and implementation:
//  - Assumes that information in the input file is correctly formatted.
//  - Patrons are stored in a STL Hash Map
//  - For STL Hash Map: 
//  - Keys must be a 4 digit id
//  - Value must be patron object
//  - Strings are only to be used in a primitive sense.
//--------------------------------------------------------------------------

class Patron {

public:

   //-----------------------------------------------------------------------
   // Patron()
   // constructor
   // default constructor for the Patron object
   Patron();

   //-----------------------------------------------------------------------
   // ~Patron()
   // destructor
   // destroys Patron object
   ~Patron();

   //-------------------------------------------------------------------------
   // patronAllowedToReturn()
   // requires the methods getLibItem() and getCommandType() from Command
   // checks if patron can return a specific book
   bool patronAllowedToReturn(LibraryItem* &other) const;

   //-----------------------------------------------------------------------
   // addCommand()
   // add a Command into Patron's history
   void addCommand(Command* commandToAdd);

   //-----------------------------------------------------------------------
   // getID()
   // returns Patron's id
   int getID() const;

   //-----------------------------------------------------------------------
   // getFirstName()
   // returns Patron's first name
   string getFirstName() const;

   //-----------------------------------------------------------------------
   // getLastName()
   // returns Patron's last name
   string getLastName() const;

   //-------------------------------------------------------------------------
   // setData()
   // sets data members of Patron object
   void setData(int patronID, ifstream& patronInfoFile);

   //-------------------------------------------------------------------------
   // display()
   // displays contents of Patron object
   void display() const;

   //-------------------------------------------------------------------------
   // displayHistory()
   // requires the method display() from Command
   // displays History of Patron object
   void displayHistory(ostream &out) const;

   //------------------------------------------------------------------------
   // displayHeader()
   // prints header for Patron output
   void displayHeader() const;

private:

   int id;            // patron ID
   string firstName;  // patron's first name
   string lastName;   // patron's last name

   vector<Command*> commandHistory;   // vector of Patron's command history

};

#endif