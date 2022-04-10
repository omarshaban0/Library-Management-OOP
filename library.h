// file library.h
// Author: Dani Shaykho and Omar Naji Shaban

#ifndef LIBRARY_H
#define LIBRARY_H

#include "commandFactory.h"
#include "treeTable.h"
#include "libraryItemFactory.h"
#include "patron.h"
#include "libraryItem.h"
#include <climits>
#include <fstream>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

//---------------------------------------------------------------------------
// Library class: Manager for all other classes. stores books, patrons, 
// and runs commands.
//
// Implementation and assumptions:
//   - Responsible for building the library (adding books in itself),
//     adding patrons in itself, and executing commands
//   - Assumes that information in the input files are correctly formatted.
//   - Must handle an invalid action code, incorrect patron ID (not found),
//     invalid format code, invalid action, and invalid book information 
//     (not found). Display error messages (as detailed as possible), but 
//     does NOT display anything when a successful command is performed.
//   - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Library {

public:

   //------------------------------------------------------------------------
   // Library()
   // default constructor
   Library();

   //------------------------------------------------------------------------
   // ~Library()
   // Destroys library object. 
   ~Library();

   //------------------------------------------------------------------------
   // buildLibrary()
   // requires methods from LibraryItem: setData()
   // requires methods from TreeTable: insert()
   // adds all library items into Library object 
   void buildLibrary();

   //------------------------------------------------------------------------
   // addPatrons()
   // Requires setData() and getID() from Patron
   // adds Patron objects into Library object 
   void addPatrons();

   //------------------------------------------------------------------------
   // executeCommands()
   // Requires setLibrary(), setData(), and execute() from Command
   // Requires createCommand() from CommandFactory
   // executes commands for Library object 
   void executeCommands();
  
   //------------------------------------------------------------------------
   // patronExists()
   // checks if patron exists 
   void retrievePatron(int patronID, Patron* &patron) const;

   //------------------------------------------------------------------------
   // createLibItem()
   // requires methods from LibraryItemFactory: createItem()
   // creates LibraryItem using itemFactory
   LibraryItem* createLibItem(char bookType);

   //------------------------------------------------------------------------
   // retrieveLibItem()
   // requires methods from TreeTable: retrieve()
   // finds LibraryItem in bstTable
   void retrieveLibItem(const LibraryItem &target, 
                           LibraryItem* &retrieved, const char bookType);

   //------------------------------------------------------------------------
   // displayLibrary()
   // requires methods from TreeTable: display()
   // print contents of the library
   void displayLibrary() const;

   //------------------------------------------------------------------------
   // displayPatrons()
   // requires methods from Patron: display() and displayHeader()
   // print all patrons in the library
   void displayPatrons() const;

private:

   CommandFactory cFactory;           // creates commands 
   LibraryItemFactory itemFactory;    // creates library items
   TreeTable bstTable;                // stores trees of LibraryItem objects
  
   unordered_map<int, Patron*> patronTable;   // hashtable of patrons

};

#endif