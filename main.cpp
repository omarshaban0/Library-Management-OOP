// file main.cpp
// Authors: Dani Shaykho and Omar Naji Shaban

#include "library.h"

#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	Library library;

	// build the library (adding books)
  library.buildLibrary();

  // add patrons into library
  library.addPatrons();

  // execute the commands
  library.executeCommands();

	return 0;
}