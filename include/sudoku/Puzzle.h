//
// Created by Kaahan Motwani on 3/22/20.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <istream>

using std::istream;
using std::string;

class Puzzle {
  //Puzzle(string line);
  friend istream& operator>>(istream is, Puzzle puzzle);
};

#endif  // PUZZLE_H
