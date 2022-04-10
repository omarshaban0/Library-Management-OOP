// file displayPatronHistory.h
// Author: Dani Shaykho and Omar Naji Shaban

#ifndef DISPLAYPATRONHISTORY_H
#define DISPLAYPATRONHISTORY_H

class Patron;

#include "command.h"
#include <iostream>

//---------------------------------------------------------------------------
// DisplayPatronHistory class: Prints the transaction history and 
// information of a specific patron in a Library object. 
// 
// Implementation and assumptions:
//     - Assumes that information in the input file is correctly formatted.
//     - Handles incorrect patron ID. 
//     - Strings are only to be used in a primitive sense.
//---------------------------------------------------------------------------

class DisplayPatronHistory : public Command {

public:

   //-----------------------------------------------------------------------
   // DisplayLibraryContents()
   // constructor
   DisplayPatronHistory();
  
   //-----------------------------------------------------------------------
   // destructor
   // destroys DisplayLibraryContents object
   ~DisplayPatronHistory();

   //-----------------------------------------------------------------------
   // create()
   // returns a DisplayPatronHistory object
	 virtual Command* create();

   //-----------------------------------------------------------------------
   // execute()
   // Requires displayHistory() from Patron
   // displays patron history, then returns false
	 virtual bool execute();

   //-------------------------------------------------------------------------
   // setData()
   // requires the method retreivePatron() from library class
   // sets data members of DisplayLibraryContents object
	 virtual bool setData(ifstream&);

   //-------------------------------------------------------------------------
   // display()
   // displays DisplayPatronHistory information
   virtual void display(ostream &out) const;


private:

   Patron* patron; // pointer to Patron

};

#endif