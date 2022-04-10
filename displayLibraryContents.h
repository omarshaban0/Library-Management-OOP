// file displayLibraryContents.h
// Author: Dani Shaykho and Omar Naji Shaban

#ifndef DISPLAYLIBRARYCONTENTS_H
#define DISPLAYLIBRARYCONTENTS_H

#include "command.h"
#include "library.h"
#include <iostream>

//---------------------------------------------------------------------------
// DisplayLibraryContents class: prints all LibraryItems in library
// 
// Implementation and assumptions:
//     - Depends on displayLibrary() to work
//     - Strings are only to be used in a primitive sense.
//---------------------------------------------------------------------------



class DisplayLibraryContents : public Command {

public:

   //-----------------------------------------------------------------------
	 // DisplayLibraryContents()
   // constructor
   DisplayLibraryContents();

	 //-----------------------------------------------------------------------
	 // destructor
	 // destroys DisplayLibraryContents object
	 virtual ~DisplayLibraryContents();

	 //-----------------------------------------------------------------------
	 // create()
	 // constructs an uninitialized DisplayLibraryContents object and
   // returns a pointer to the object
	 virtual Command* create();

   //-----------------------------------------------------------------------
   // execute()
   // Requires displayLibrary() from Library
   // displays library contents, then returns false
	 virtual bool execute();

   //-------------------------------------------------------------------------
   // setData()
   // sets data members of Checkout object
   virtual bool setData(ifstream& commandInfoFile);

   //-------------------------------------------------------------------------
   // display()
   // displays DisplayLibraryContents information
   virtual void display(ostream &out) const;

};

#endif