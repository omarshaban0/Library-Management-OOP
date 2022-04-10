// file periodical.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "periodical.h"

//----------------------------------------------------------------------------
// Periodical()
// Constructor
Periodical::Periodical() {
   title = "";
   year = -1;
   month = -1;
   type = 'P';
   copiesAvailable = 1;
}

//----------------------------------------------------------------------------
// ~Periodical()
// destructor
// destroys Periodical object
Periodical::~Periodical() {}

//----------------------------------------------------------------------------
// create()
// creates and returns a Periodical object
LibraryItem * Periodical::create() {
   return new Periodical();
}

//----------------------------------------------------------------------------
// setData()
// sets data members of Periodical object
void Periodical::setData(ifstream& bookInfoFile) {
   bookInfoFile.get(); // skip blank before title
   getline(bookInfoFile, title, ',');
   bookInfoFile >> month;
   bookInfoFile >> year;
}

//----------------------------------------------------------------------------
// setCommandData()
// sets data members of temp Periodical object for Command
// command classes call this method
void Periodical::setCommandData(ifstream& commandInfoFile) {
   commandInfoFile >> year;
   commandInfoFile >> month;
   commandInfoFile.get(); // skip blank before title
   getline(commandInfoFile, title, ',');
}

//----------------------------------------------------------------------------
// display()
// displays Periodical object
void Periodical::display(ostream& out) const {
   out << setw(8) << left << copiesAvailable;
   out << setw(40) << left << title;
   out << setw(5) << right << month;
   out << setw(6) << right << year << endl;
}

//------------------------------------------------------------------------
// displayHeader()
// prints header for Periodical output
void Periodical::displayHeader(ostream& out) const {
   out << "PERIODICALS" << endl;
   out << setw(48) << left << "AVAIL   TITLE";
   out << "MONTH  YEAR" << endl << endl;
}

//----------------------------------------------------------------------------
// displaySpecific()
// display certain variables in Periodical object
void Periodical::displaySpecific(ostream& out) const {
   out << title;
}

//----------------------------------------------------------------------------
// patronHistoryDisplay()
// display periodical object
// used when displaying the patron history
void Periodical::patronHistoryDisplay(ostream& out) const {
   out << setw(2) << right << month;
   out << setw(6) << right << year;
   out << "  ";
   out << setw(40) << left << title << endl;
}

//----------------------------------------------------------------------------
// increaseCount()
// increases count of copiesAvailable
bool Periodical::increaseCount() {
   if (copiesAvailable < 1) {
      copiesAvailable++;
      return true;
   }
   return false;
}

//----------------------------------------------------------------------------
// operator>
// checks if calling object is bigger than other object
bool Periodical::operator > (const LibraryItem& other) const {

   // typecast other Periodical class
   const Periodical& otherPeriodical = static_cast <const Periodical&>(other);

   // handling if variables are same
   if (year != otherPeriodical.year) {
      return year > otherPeriodical.year;
   } else if (month != otherPeriodical.month) {
      return month > otherPeriodical.month;
   } else {
      return title > otherPeriodical.title;
   }
}

//----------------------------------------------------------------------------
// operator<
// checks if calling object is smaller than other object
bool Periodical::operator < (const LibraryItem& other) const {

   // typecast other Periodical class
   const Periodical& otherPeriodical = static_cast <const Periodical&>(other);

   // handling if variables are same
   if (year != otherPeriodical.year) {
      return year < otherPeriodical.year;
   } else if (month != otherPeriodical.month) {
      return month < otherPeriodical.month;
   } else {
      return title < otherPeriodical.title;
   }
}

//----------------------------------------------------------------------------
// operator==
// checks if two objects are equal
bool Periodical::operator==(const LibraryItem& other) const {

   // typecast other Periodical class
   const Periodical& otherPeriodical = static_cast <const Periodical&>(other);

   return title == otherPeriodical.title && year == otherPeriodical.year &&
      month == otherPeriodical.month;
}

//----------------------------------------------------------------------------
// operator<=
// checks if calling object is smaller/equal than other object
bool Periodical::operator<=(const LibraryItem& other) const {

   // typecast other Periodical class
   const Periodical& otherPeriodical = static_cast <const Periodical&>(other);

   return *this == otherPeriodical || *this < otherPeriodical;
}

//----------------------------------------------------------------------------
// operator>=
// checks if calling object is bigger/equal than other object
bool Periodical::operator>=(const LibraryItem& other) const {

   // typecast other Periodical class
   const Periodical& otherPeriodical = static_cast <const Periodical&>(other);

   return *this == otherPeriodical || *this > otherPeriodical;
}

//----------------------------------------------------------------------------
// setMonth()
// sets month of Periodical object
void Periodical::setMonth(int month) {
   this->month = month;
}