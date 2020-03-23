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
    //vector<Puzzle> puzzles;
    std::istream& input_stream = puzzle_stream;

    string tag;
    input_stream >> tag;


    //std::cout << tag << std::endl;

    string line;
    if (tag == "#spf1.0") {
      while (std::getline(puzzle_stream, line)) {
        if (line.length() == 81 && ContainsValidCharacters(line)) {
          //std::istringstream str(line);
          std::cout << line << std::endl;
          std::cout << "valid" << std::endl;
//          Puzzle p(line);
//        str >> p;
//        puzzles.push_back(p);
        }
//      Puzzle puzzle;
//      line >> puzzle;  // Initialize the puzzle
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
    std::cout << "You need to provide a Sudoku file through command line "
                 "arguments!" << std::endl;
    exit(0);
  }

  return 0;
}

bool ContainsValidCharacters(string line) {
  // a string of valid digits
  string digits_string = "123456789";
  std::vector<char> digits;
  for (char digit : digits_string) { // for each char in digits_string
    digits.push_back(digit);
  }

  for(char& c : line) {
    if (c != '_' && !(std::find(digits.begin(), digits.end(), c)
      != digits.end())) {
      return false;
    }
  }
  return true;
}






