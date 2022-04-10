// file childrens.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "childrens.h"

//----------------------------------------------------------------------------
// Childrens()
// Constructor
Childrens::Childrens() {
   author = "";
   title = "";
   year = -1;
   type = 'C';
   copiesAvailable = 5;
}

//----------------------------------------------------------------------------
// ~Childrens()
// destructor 
// destroys Childrens object
Childrens::~Childrens() {}

//----------------------------------------------------------------------------
// create()
// creates and returns a Childrens object
LibraryItem* Childrens::create() {
   return new Childrens();
}

//----------------------------------------------------------------------------
// setData()
// reads data file and sets data members of Childrens object
void Childrens::setData(ifstream& bookInfoFile) {
   bookInfoFile.get();                   // skip blank before author
   getline(bookInfoFile, author, ',');
   bookInfoFile.get();                   // skip blank before title
   getline(bookInfoFile, title, ',');
   bookInfoFile >> year;
}

//----------------------------------------------------------------------------
// setCommandData()
// sets data members of temp Childrens object for Command
// command classes call this method
void Childrens::setCommandData(ifstream& commandInfoFile) {
   commandInfoFile.get();                 // skip blank before author
   getline(commandInfoFile, title, ',');
   commandInfoFile.get();                 // skip blank before title
   getline(commandInfoFile, author, ',');
}

//----------------------------------------------------------------------------
// display()
// displays Childrens object
void Childrens::display(ostream& out) const {
   out << setw(8) << left << copiesAvailable;
   out << setw(27) << left << author;
   out << setw(40) << left << title;
   out << year << endl;
}

//------------------------------------------------------------------------
// displayHeader()
// prints header for Children object output
void Childrens::displayHeader(ostream& out) const {
   out << "CHILDRENS BOOKS" << endl;
   out << setw(35) << left << "AVAIL   AUTHOR";
   out << setw(40) << left << "TITLE";
   out << "YEAR" << endl << endl;
}

//----------------------------------------------------------------------------
// displaySpecific()
// display certain variables in Childrens object
void Childrens::displaySpecific(ostream& out) const {
   out << title;
}

//----------------------------------------------------------------------------
// patronHistoryDisplay()
// display Childrens object
// used when displaying the patron history
void Childrens::patronHistoryDisplay(ostream& out) const {
   out << setw(40) << left << title;
   out << setw(27) << left << author;
   out << year << endl;
}

//----------------------------------------------------------------------------
// increaseCount()
// increases count of copiesAvailable
bool Childrens::increaseCount() {
   if (copiesAvailable < 5) {
      copiesAvailable++;
      return true;
   }
   return false;
}

//----------------------------------------------------------------------------
// operator>
// checks if calling object is bigger than other object
bool Childrens::operator>(const LibraryItem & other) const {

   // typecast other to Childrens class
   const Childrens& otherChild = static_cast <const Childrens&> (other);

   // if titles are same
   if (title == otherChild.title) {
      return author > otherChild.author;
   }

   return title > otherChild.title;
}

//----------------------------------------------------------------------------
// operator<
// checks if calling object is smaller than other object
bool Childrens::operator<(const LibraryItem & other) const {

   // typecast other to Childrens class
   const Childrens& otherChild = static_cast <const Childrens&> (other);

   // if titles are same
   if (title == otherChild.title) {
      return author < otherChild.author;
   }

   return title < otherChild.title;
}

//----------------------------------------------------------------------------
// operator==
// checks if two objects are equal
bool Childrens::operator==(const LibraryItem & other) const {

   // typecast other to Childrens class
   const Childrens& otherChild = static_cast <const Childrens&> (other);

   return title == otherChild.title && author == otherChild.author;
}

//----------------------------------------------------------------------------
// operator<=
// checks if calling object is smaller/equal than other object
bool Childrens::operator<=(const LibraryItem & other) const {

   // typecast other to Childrens class
   const Childrens& otherChild = static_cast <const Childrens&> (other);

   return *this == otherChild || *this < otherChild;
}

//----------------------------------------------------------------------------
// operator>=
// checks if calling object is bigger/equal than other object
bool Childrens::operator>=(const LibraryItem & other) const {

   // typecast other to Childrens class
   const Childrens& otherChild = static_cast <const Childrens&> (other);

   return *this == otherChild || *this > otherChild;
}

//----------------------------------------------------------------------------
// setAuthor()
// sets author of Childrens object
void Childrens::setAuthor(string author) {
   this->author = author;
}