// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#include <sudoku/Puzzle.h>

#include <fstream>
#include <iostream>
#include <stdexcept>
//#include <istringstream>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

/**
 *
 * @param line
 * @return
 */
bool ContainsValidCharacters(string line);

int main(int argc, char** argv) {
  if (argc > 1) {
    std::ifstream puzzle_stream(argv[1]);

    if (puzzle_stream.fail()) {
      throw std::invalid_argument("The file could not open!");
      // Handle read error by throwing invalid argument exception
    }

    std::istream& input_stream = puzzle_stream;
    string tag; // Represents the first line in the spf file
    input_stream >> tag;
    std::cout << tag << std::endl;

    string line;
    if (tag == "#spf1.0") {
      while (std::getline(puzzle_stream, line)) {

        if (line.length() == 81 && ContainsValidCharacters(line)) {
          //std::istringstream str(line);
          cout << line << endl;
          cout << "valid" << endl;
          Puzzle puzzle;
          std::istringstream input(line);
          //std::istream& istream1 = input;
          input >> puzzle;
        }
        //cout << "random" << endl;
//      std::cout << puzzle << std::endl;  // Print the solved puzzle
      }
    }




//    string line;
//    while (std::getline(puzzle_stream, line))
//    {
//      std::istringstream iss(line);
//      int a, b;
//      if (!(iss >> a >> b)) { break; } // error
//
//      // process pair (a,b)
//    }

  } else {
    cout << "You need to provide a Sudoku file through command line "
                 "arguments!" << endl;
    exit(0);
  }

  return 0;
}

bool ContainsValidCharacters(string line) {
  // a string of valid digits in a sudoku puzzle
  string digits_string = "123456789";
  std::vector<char> digits;
  for (char digit : digits_string) { // for each char in digits_string
    digits.push_back(digit);
  }

  //iterating through the given sudoku puzzle
  for (char& c : line) {
    bool do_chars_exist = std::find(digits.begin(), digits.end(), c)
        != digits.end();
    if (c != '_' && !(do_chars_exist)) {
      return false;
    }
  }
  return true;
}






