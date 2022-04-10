// file checkout.h
// Author: Dani Shaykho and Omar Naji Shaban

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "command.h"
#include "libraryItem.h"
#include "library.h"
#include <string>

//----------------------------------------------------------------------------
// Checkout class: Sends instructions to Library class to checkout a book
// 
// Implementation and assumptions:
//     - Assumes that information in the input file is correctly formatted.
//     - Must handle an invalid action code, incorrect patron ID (not found),
//       invalid format code, invalid action, and invalid book information 
//       (not found). Display error messages (as detailed as possible), but 
//       does NOT display anything when a successful command is performed.
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Checkout : public Command {

public:

   //-----------------------------------------------------------------------
   // Checkout()
   // constructor
   Checkout();

   //-----------------------------------------------------------------------
   // ~Checkout()
   // destructor
   // destroys Checkout object
   virtual ~Checkout();

   //-----------------------------------------------------------------------
   // create()
   // return a Checkout object
   virtual Command* create();

   //-----------------------------------------------------------------------
   // execute()
   // requires methods from Patron: getFirstName(), getLastName(),
   // and addCommand()
   // requires methods from Library: decreaseCount() and displaySpecific()
   // checksout book and adds command to patron history
   virtual bool execute();

   //-------------------------------------------------------------------------
   // setData()
   // requires the methods from Patron: getFirstName() and getLastName()
   // requires the methods from LibraryItem: setCommandData(), 
   // displaySpecific()
   // requires the methods from Library: retrievePatron(), createLibItem(),
   // and retrieveLibItem()
   // sets data members of Checkout object
   virtual bool setData(ifstream& commandInfoFile);

   //-------------------------------------------------------------------------
   // display()
   // displays Checkout information
   virtual void display(ostream &out) const;

private:

   Patron* patron;         // used to set patron history
	 char bookType;   	      // the type of book
	 char bookFormat; 	      // the format of the book

};

#endif