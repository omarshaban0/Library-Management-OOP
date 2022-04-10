// file book.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "book.h"

//----------------------------------------------------------------------------
// Book()
// Constructor
Book::Book() {
   title = "";
   year = -1;
   type = 'B';
}

//----------------------------------------------------------------------------
// ~Book()
// Destructor
// destroys Book object
Book::~Book() {}

//----------------------------------------------------------------------------
// getTitle()
// gets title of Book object
string Book::getTitle() {
   return title;
}