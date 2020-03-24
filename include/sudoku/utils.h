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
  *
  * @param puzzle_line
  * @return
   */
  bool ContainsValidCharacters(const string& puzzle_line);

  /**
   *
   * @param puzzle_stream
   * @return
   */
  string PrintSolvedPuzzle(const string& puzzle_line);

  /**
   *
   * @param puzzle_stream
   * @return
   */
  string ReturnTag(std::ifstream& puzzle_stream);

}
#endif  // SUDOKU_UTILS_H
