//
// Created by Kaahan Motwani on 3/24/20.
//

#ifndef SUDOKU_UTILS_H
#define SUDOKU_UTILS_H

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace utils {

  /**
  * This method checks if a given puzzle line contains only underscores and digits and returns true if so
  *
  * @param puzzle_line one line that represents a single game of Sudoku
  * @return whether the string contained valid characters or not
   */
  bool ContainsValidCharacters(const string& puzzle_line);

  /**
   * This method uses the overloaded operators in the Puzzle class to solve an spf file of puzzles
   *
   * @param puzzle_line one line that represents a single game of Sudoku
   * @return a string of the solved puzzle; also printed in this method using overloaded operators
   */
  string ReturnAndPrintSolvedPuzzle(const string& puzzle_line);

  /**
   * This method returns the first line of the spf file (tag)
   *
   * @param puzzle_stream an ifstream of the spf file with all lines
   * @return the first line in the spf file
   */
  string ReturnTag(std::ifstream& puzzle_stream);

}
#endif  // SUDOKU_UTILS_H
