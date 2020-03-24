// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#include <sudoku/Puzzle.h>

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

/**
 *
 * @param puzzle_line
 * @return
 */
bool ContainsValidCharacters(const string& puzzle_line);

int main(int argc, char** argv) {
  if (argc > 1) {
    std::ifstream puzzle_stream(argv[1]);

    if (puzzle_stream.fail()) {
      throw std::invalid_argument("The file could not open!");
      // Handle read error
    }

    std::istream& input_stream = puzzle_stream;
    string tag; // Represents the first line in the spf file as a string
    input_stream >> tag; // Puts the contents of the first line into tag
    string puzzle_line; // Represents a line that is a puzzle from the spf file
    const int kPuzzleLength = 81;
    if (tag == "#spf1.0") {
      while (std::getline(puzzle_stream, puzzle_line)) {
        if (puzzle_line.length() == kPuzzleLength
          && ContainsValidCharacters(puzzle_line)) {
          cout << puzzle_line << endl;
          //cout << "valid" << endl;
          Puzzle puzzle;
          std::istringstream input(puzzle_line);
          input >> puzzle;
          cout << puzzle << endl;
        }
      }
    }
  } else {
    cout << "You need to provide a Sudoku file through command line "
                 "arguments!" << endl;
    exit(0);
  }

  return 0;
}

bool ContainsValidCharacters(const string& puzzle_line) {
  // digits_string is a string of valid digits in a sudoku puzzle
  string digits_string = "123456789";
  vector<char> digits;
  // Adds all digits to a vector of chars
  for (char digit : digits_string) {
    digits.push_back(digit);
  }

  // Iterating through the given Sudoku puzzle and ensuring that the only
  // characters in the puzzle are digits 1 - 9 and '_'
  for (char c : puzzle_line) {
    bool do_chars_exist = std::find(digits.begin(), digits.end(), c)
        != digits.end();
    if (c != '_' && !(do_chars_exist)) {
      return false;
    }
  }
  return true;
}






