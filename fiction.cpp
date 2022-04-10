// file fiction.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "fiction.h"

//----------------------------------------------------------------------------
// Fiction()
// Constructor
Fiction::Fiction() {
   author = "";
   title = "";
   year = -1;
   type = 'F';
   copiesAvailable = 5;
}

//----------------------------------------------------------------------------
// ~Fiction()
// destructor
// destroys Fiction object
Fiction::~Fiction() {}

//----------------------------------------------------------------------------
// create()
// creates and returns a Fiction object
LibraryItem* Fiction::create() {
   return new Fiction();
}

//----------------------------------------------------------------------------
// setData()
// sets data members of Fiction object
void Fiction::setData(ifstream& bookInfoFile) {
   bookInfoFile.get(); // skip blank before author
   getline(bookInfoFile, author, ',');
   bookInfoFile.get(); // skip blank before title
   getline(bookInfoFile, title, ',');
   bookInfoFile >> year;
}

//----------------------------------------------------------------------------
// setCommandData()
// sets data members of temp Fiction object for Command
// Command classes call this method
void Fiction::setCommandData(ifstream& commandInfoFile) {
   commandInfoFile.get(); // skip blank before author
   getline(commandInfoFile, author, ',');
   commandInfoFile.get(); // skip blank before title
   getline(commandInfoFile, title, ',');
}

//----------------------------------------------------------------------------
// display()
// displays Fiction object
void Fiction::display(ostream& out) const {
   out << setw(8) << left << copiesAvailable;
   out << setw(27) << left << author;
   out << setw(40) << left << title;
   out << year << endl;
}

//------------------------------------------------------------------------
// displayHeader()
// prints header for Fiction object output
void Fiction::displayHeader(ostream& out) const {
   out << "FICTION BOOKS" << endl;
   out << setw(35) << left << "AVAIL   AUTHOR";
   out << setw(40) << left << "TITLE";
   out << "YEAR" << endl << endl;
}

//----------------------------------------------------------------------------
// displaySpecific()
// display certain variables in Fiction object
void Fiction::displaySpecific(ostream& out) const {
   out << title;
}

//----------------------------------------------------------------------------
// patronHistoryDisplay()
// display fiction object
// used when displaying the patron history
void Fiction::patronHistoryDisplay(ostream & out) const {
   out << setw(27) << left << author;
   out << setw(40) << left << title;
   out << year << endl;
}

//----------------------------------------------------------------------------
// increaseCount()
// increases count of copiesAvailable
bool Fiction::increaseCount() {
   if (copiesAvailable < 5) {
      copiesAvailable++;
      return true;
   }
   return false;
}

//----------------------------------------------------------------------------
// operator>
// checks if calling object is bigger than other object
bool Fiction::operator>(const LibraryItem & other) const {

   // typecast other Fiction class
   const Fiction& otherFiction = static_cast <const Fiction&> (other);

   // if authors are same
   if (author == otherFiction.author) {
      return title > otherFiction.title;
   }

   return author > otherFiction.author;
}

//----------------------------------------------------------------------------
// operator<
// checks if calling object is smaller than other object
bool Fiction::operator < (const LibraryItem& other) const {

   // typecast other to Fiction class
   const Fiction& otherFiction = static_cast <const Fiction&> (other);

   // if authors are same
   if (author == otherFiction.author) {
      return title < otherFiction.title;
   }

   return author < otherFiction.author;
}

//----------------------------------------------------------------------------
// operator==
// checks if two objects are equal
bool Fiction::operator==(const LibraryItem& other) const {

   // typecast other Fiction class
   const Fiction& otherFiction = static_cast <const Fiction&> (other);
   return title == otherFiction.title && author == otherFiction.author;
}

//----------------------------------------------------------------------------
// operator<=
// checks if calling object is smaller/equal than other object
bool Fiction::operator<=(const LibraryItem& other) const {

   // typecast other Fiction class
   const Fiction& otherFiction = static_cast <const Fiction&> (other);

   return *this == otherFiction || *this < otherFiction;
}

//----------------------------------------------------------------------------
// operator>=
// checks if calling object is bigger/equal than other object
bool Fiction::operator>=(const LibraryItem& other) const {

   // typecast other Fiction class
   const Fiction& otherFiction = static_cast <const Fiction&> (other);

   return *this == otherFiction || *this > otherFiction;
}

//----------------------------------------------------------------------------
// setAuthor()
// sets author of Fiction object
void Fiction::setAuthor(string author) {
   this->author = author;
}