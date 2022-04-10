// file commandfactory.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "commandFactory.h"
#include "command.h"
#include "checkout.h"
#include "return.h"
#include "displayLibraryContents.h"
#include "displayPatronHistory.h"

//-----------------------------------------------------------------------
// CommandFactory()
// Initializes the contents of libraryItemTable with nullptr or pointers
// requires the method hash()
// constructor
CommandFactory::CommandFactory() {
   for (int i = 0; i < 52; i++) {
      commandTable[i] = nullptr;
   }
   commandTable[hash('C')] = new Checkout();
   commandTable[hash('R')] = new Return();
   commandTable[hash('D')] = new DisplayLibraryContents();
   commandTable[hash('H')] = new DisplayPatronHistory();
}

//-----------------------------------------------------------------------
// ~CommandFactory()
// Deallocates all command object pointers in commandTable. 
CommandFactory::~CommandFactory() {
   for (int i = 0; i < 52; i++) {
      delete commandTable[i];
      commandTable[i] = nullptr;
   }
}

//-----------------------------------------------------------------------
// createCommand()
// Create and return a new Command object that corresponds to 'key'.
// Returns nullptr if key does not correspond to any Command object.
Command * CommandFactory::createCommand(char key) const {
   int subscript = hash(key); // would do error checking

   // checks if object does not exist in factory
   if (subscript == -1 || commandTable[subscript] == nullptr) {
      return nullptr;
   }

   return commandTable[subscript]->create();
}

//-----------------------------------------------------------------------
// hash()
// converts a alphabetical character input into an integer index
int CommandFactory::hash(char type) const {
   // if character is not alphabetical
   if (!isalpha(type)) {
      return -1;
   }

   // get ascii for uppcase character
   char upperCaseChar = toupper(type);
   //cout << int(upperCaseChar) - 65 << endl;
   return (int(upperCaseChar) - 65);
}