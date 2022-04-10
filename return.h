// file return.h
// Author: Dani Shaykho and Omar Naji Shaban

#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include "libraryItem.h"
#include "library.h"
#include <string>

//----------------------------------------------------------------------------
// Return class: Sends instructions to the Library class to return a book
// 
// Implementation and assumptions:
//     - Assumes that information in the input file is correctly formatted.
//     - Must handle an invalid action code, incorrect patron ID (not found),
//       invalid format code, invalid action, and invalid book information 
//       (not found). Display error messages (as detailed as possible), but 
//       does NOT display anything when a successful command is performed.
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Return : public Command {

public:

   //-----------------------------------------------------------------------
   // Return()
   // constructor
   Return();

   //-----------------------------------------------------------------------
   // destructor
   // destroys Return object
   virtual ~Return();

   //-----------------------------------------------------------------------
   // create()
   // return a Return object
   virtual Command* create();

   //-----------------------------------------------------------------------
   // execute()
   // requires the methods from Patron: patronAllowedToReturn(),
   // getFirstName(), getLastName(), and addCommand()
   // requires the methods from Library: increaseCount(), displaySpecific()
   // returns book and adds command to patron history
   virtual bool execute();

   //-------------------------------------------------------------------------
   // setData()
   // requires the methods from Patron: getFirstName(), getLastName(),
   // requires the methods from LibraryItem: setCommandData(),
   // increaseCount(), displaySpecific()
   // requires the methods from Library:retrievePatron(), createLibItem(),
   // and retrieveLibItem()
   // sets data members of Return object
   virtual bool setData(ifstream& commandInfoFile);

   //-------------------------------------------------------------------------
   // display()
   // requires the method patronHistoryDisplay() from LibraryItem
   // displays Return information in patron history
   virtual void display(ostream &out) const;

private:

   Patron* patron;         // used to set patron history
   char bookType;   	      // the type of book
   char bookFormat; 	      // the format of the book

};

#endif