// file commandFactory.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

class Command;

#include "iostream"

using namespace std;

//---------------------------------------------------------------------------
// CommandFactory class: Creates and returns Command objects corresponding
//     to an input character key.
// 
// Implementation and assumptions:
//     - Currently needs the classes Checkout, Return, DisplayLibrary,
//       and DisplayPatronHistory to be fully implemented
//     - Currently only returns Checkout, Return, DisplayLibrary, and
//       DisplayPatronHistory objects
//     - Strings are only to be used in a primitive sense.
//---------------------------------------------------------------------------

class CommandFactory {

public:

   //-----------------------------------------------------------------------
   // CommandFactory()
   // Initializes the contents of libraryItemTable with nullptr or pointers
   // requires the method hash()
   // constructor
   CommandFactory();

   //-----------------------------------------------------------------------
   // ~CommandFactory()
   // Deallocates all command object pointers in commandTable. 
   ~CommandFactory();

   //-----------------------------------------------------------------------
   // createCommand()
   // Create and return a new Command object that corresponds to 'key'.
   // Returns nullptr if key does not correspond to any Command object.
   Command* createCommand(char key) const;

private:

   //-----------------------------------------------------------------------
   // Array of Command pointers.
   // Contains each derived class object of Command that is called to
   // create a new Command object. 
   Command* commandTable[52];
  
   //-----------------------------------------------------------------------
   // hash()
   // converts a alphabetical character input into an integer index
   int hash(char key) const;

};

#endif