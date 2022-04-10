// file library.h
// Author: Dani Shaykho and Omar Naji Shaban

#include "library.h"

//------------------------------------------------------------------------
// Library()
// default constructor
Library::Library() {}

//------------------------------------------------------------------------
// ~Library()
// Destroys library object. 
Library::~Library() {
   for (auto i = patronTable.begin(); i != patronTable.end(); i++) {
      delete i->second;
      i->second = nullptr;
   }
   patronTable.clear();
}

//------------------------------------------------------------------------
// buildLibrary()
// requires methods from LibraryItem: setData()
// requires methods from TreeTable: insert()
// adds all library items into Library object 
void Library::buildLibrary() {
   char key; // book type
   LibraryItem* libItem;

   // open the data file containing book info
   ifstream bookListFile("data4books.txt");
   if (!bookListFile) {
      cout << "File could not be opened." << endl;
      return;
   }

   while (true) {
      bookListFile >> key; // reads book type
      if (bookListFile.eof()) {
         break;
      }
      libItem = createLibItem(key);

      // if Library Item doesn't exist, skip line
      if (libItem == nullptr) {
         cout << "ERROR: " << key << " is not a valid LibItem type." << endl;
         cout << endl;
         string s;
         getline(bookListFile, s);
         continue;
      }

      libItem->setData(bookListFile); // set data members of object
      bool success;
      success = bstTable.insert(key, libItem);
   }
}

//------------------------------------------------------------------------
// addPatrons()
// Requires setData() and getID() from Patron
// adds Patron objects into Library object 
void Library::addPatrons() {
   int patronID; // patron ID

   // open the data file containing patron info
   ifstream patronListFile("data4patrons.txt");
   if (!patronListFile) {
      cout << "File could not be opened." << endl;
      return;
   }

   while (true) {
      patronListFile >> patronID; // reads patron ID
      if (patronListFile.eof()) {
         break;
      }

      // if adding duplicate Patron, skip line

      Patron* patron = new Patron;
      patron->setData(patronID, patronListFile); // set data members of object
      patronTable.insert({
         patron->getID(),
         patron
      });
   }
}

//------------------------------------------------------------------------
// executeCommands()
// Requires setLibrary(), setData(), and execute() from Command
// Requires createCommand() from CommandFactory
// executes commands for Library object 
void Library::executeCommands() {
   char key; // command type
   Command* aCommand;
   bool dataSuccessfullySet; // if data of command is set
   bool executedSuccessfully; // if command executed

   // open the data file containing command info
   ifstream commandListFile("data4commands.txt");
   if (!commandListFile) {
      cout << "File could not be opened." << endl;
      return;
   }

   while (true) {
      commandListFile >> key; // reads command type
      if (commandListFile.eof()) {
         break;
      }

      aCommand = cFactory.createCommand(key);

      // if Command type doesn't exist, skip line
      if (aCommand == nullptr) {
         cout << "ERROR: " << key << " is not a valid Command type." << endl;
         cout << endl;

         // skip line in data file
         string s;
         getline(commandListFile, s);
         continue;
      }

      // set data for Command object and execute command
      aCommand->setLibrary(this);
      dataSuccessfullySet = aCommand->setData(commandListFile);
      if (dataSuccessfullySet) {
         executedSuccessfully = aCommand->execute();
         if (!executedSuccessfully) {
            delete aCommand;
            aCommand = nullptr;
         }
      } else {
         delete aCommand;
         aCommand = nullptr;

         // skip line in data file
         string garbage;
         getline(commandListFile, garbage);
         continue;
         //commandListFile.ignore(LONG_MAX, '\n');
      }
   }
}

//------------------------------------------------------------------------
// patronExists()
// checks if patron exists 
void Library::retrievePatron(int patronID, Patron * & patron) const {
   if (patronTable.find(patronID) != patronTable.end()) {
      patron = patronTable.at(patronID);
   }
}

//------------------------------------------------------------------------
// createItem()
// requires methods from LibraryItemFactory: createItem()
// creates LibraryItem using itemFactory
LibraryItem* Library::createLibItem(char bookType) {
   return itemFactory.createItem(bookType);
}

//------------------------------------------------------------------------
// retrieveLibItem()
// requires methods from TreeTable: retrieve()
// finds LibraryItem in bstTable
void Library::retrieveLibItem(const LibraryItem& target,
   LibraryItem*& retrieved,
   const char bookType) {
   bstTable.retrieve(target, retrieved, bookType);
}

//------------------------------------------------------------------------
// displayLibrary()
// requires methods from TreeTable: display()
// print contents of the library
void Library::displayLibrary() const {
   bstTable.display();
}

//------------------------------------------------------------------------
// displayPatrons()
// requires methods from Patron: display() and displayHeader()
// print all patrons in the library
void Library::displayPatrons() const {
   for (auto i = patronTable.begin(); i != patronTable.end(); i++) {
      if (i == patronTable.begin()) {
         i->second->displayHeader();
      }
      i->second->display();
   }
}