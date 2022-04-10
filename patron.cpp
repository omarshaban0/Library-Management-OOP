// file patron.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "patron.h"
#include "libraryItem.h"

//-----------------------------------------------------------------------
// Patron()
// constructor
// default constructor for the Patron object
Patron::Patron() {
   id = 0000;
   firstName = "";
   lastName = "";
}

//-----------------------------------------------------------------------
// ~Patron()
// destructor
// destroys Patron object
Patron::~Patron() {
   for (auto& command: commandHistory) {
      delete command;
      command = nullptr;
   }
}

//----------------------------------------------------------------------------
// patronAllowedToReturn()
// requires the methods getLibItem() and getCommandType() from Command
// checks if patron can return a specific book
bool Patron::patronAllowedToReturn(LibraryItem*& other) const {
   int checkoutCounter = 0; // # of times book checked-out
   int returnCounter = 0; // # of times book returned

   // count how many times patron checked-out or returned a certain book
   for (auto & command: commandHistory) {
      if ( * (command->getLibItem()) == *other) {
         if (command->getCommandType() == "CheckOut") {
            checkoutCounter++;
         }
         if (command->getCommandType() == "Return") {
            returnCounter++;
         }
      }
   }

   // if more checkouts than returns, patron allowed to return
   if (checkoutCounter > returnCounter) {
      return true;
   }
   return false;
}

//-----------------------------------------------------------------------
// addCommand()
// add a Command into Patron's history
void Patron::addCommand(Command* commandToAdd) {
   commandHistory.push_back(commandToAdd);
}

//-----------------------------------------------------------------------
// getID()
// returns Patron's id
int Patron::getID() const {
   return id;
}

//-----------------------------------------------------------------------
// getFirstName()
// returns Patron's first name
string Patron::getFirstName() const {
   return firstName;
}

//-----------------------------------------------------------------------
// getLastName()
// returns Patron's last name
string Patron::getLastName() const {
   return lastName;
}

//----------------------------------------------------------------------------
// setData()
// sets data members of Patron object
void Patron::setData(int patronID, ifstream& patronInfoFile) {
   id = patronID;
   patronInfoFile >> lastName;
   patronInfoFile >> firstName;
}

//----------------------------------------------------------------------------
// display()
// displays contents of Patron object
void Patron::display() const {
   cout << setw(7) << left << id;
   cout << setw(12) << left << lastName;
   cout << setw(12) << left << firstName << endl;
}

//----------------------------------------------------------------------------
// displayHistory()
// requires the method display() from Command
// displays History of Patron object
void Patron::displayHistory(ostream& out) const {
   cout << "PATRON HISTORY" << endl;
   cout << setw(7) << left << "ID";
   cout << setw(12) << left << "LASTNAME";
   cout << setw(12) << left << "FIRSTNAME" << endl;
   cout << endl;
   cout << setw(7) << left << id;
   cout << setw(12) << left << lastName;
   cout << setw(12) << left << firstName << ":" << endl;
   cout << endl;
   for (auto& command: commandHistory) {
      command -> display(out);
   }
   cout << endl;
}

//------------------------------------------------------------------------
// displayHeader()
// prints header for Patron output
void Patron::displayHeader() const {
   cout << "PATRONS" << endl;
   cout << setw(7) << left << "ID";
   cout << setw(12) << left << "LASTNAME";
   cout << setw(12) << left << "FIRSTNAME" << endl;
   cout << endl;
}