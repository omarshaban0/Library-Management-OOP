// file book.h
// Authors: Dani Shaykho and Omar Naji Shaban

#ifndef BOOK_H
#define BOOK_H

#include "libraryItem.h"

//----------------------------------------------------------------------------
// Book class: Acts as interface for book sub-classes
// 
// Assumptions and implementation:
//     - Assume that a "Book" object will not be created
//     - Strings are only to be used in a primitive sense.
//----------------------------------------------------------------------------

class Book : public LibraryItem {

public:

  //--------------------------------------------------------------------------
  // Book()
  // Constructor
  Book();

  //--------------------------------------------------------------------------
  // ~Book()
  // Destructor
  // destroys Book object
  virtual ~Book();

  //--------------------------------------------------------------------------
  // getTitle()
  // gets title of Book object
  string getTitle();

protected:

  string title;    // title of book
  int year;        // year of book
  char type;       // type of book

};

#endif