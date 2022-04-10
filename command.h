// file command.h
// Author: Dani Shaykho and Omar Naji Shaban

#ifndef COMMAND_H
#define COMMAND_H

class Library;
class LibraryItem;

#include <fstream>
#include <iostream>

using namespace std;

//----------------------------------------------------------------------------
// Command class: Super class (interface for Commands that inherit
// this class).
// 
// Assumptions and implementation:
//     - Assume that a "Command" object will not be created
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Command {

public:

	 //-----------------------------------------------------------------------
   // ~Command()
	 // destructor
	 // destroys Command object
	 virtual ~Command();

	 //-----------------------------------------------------------------------
	 // create()
	 // creates and returns a Command object
	 virtual Command* create() = 0;

 	 //-----------------------------------------------------------------------
	 // execute()
	 // send command to Library object
	 virtual bool execute() = 0;

   //-------------------------------------------------------------------------
   // setData()
   // sets data members of Command object
   virtual bool setData(ifstream& commandInfoFile) = 0;

   //-------------------------------------------------------------------------
   // display()
   // displays Command information
   virtual void display(ostream &out) const = 0;

   //-------------------------------------------------------------------------
   // setLibrary()
   // sets library
   void setLibrary(Library* libraryPtr);

   //-------------------------------------------------------------------------
   // getCommandType()
   // returns command type 
   string getCommandType() const;

   //-------------------------------------------------------------------------
   // getLibItem()
   // returns library item pointer
   LibraryItem* getLibItem() const;

protected:

   Library* library;      // pointer to library object
   string commandType;    // type of command
   LibraryItem* libItem;  // used in return and checkout

};

#endif