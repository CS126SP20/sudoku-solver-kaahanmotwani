//
// Created by Kaahan Motwani on 3/22/20.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <istream>

using std::istream;
using std::string;

class Puzzle {
  public:
  Puzzle();
  Puzzle(const string& line);
    friend istream& operator>>(istream& is, Puzzle puzzle);
    friend std::istream& operator<<(std::ostream& os, const Puzzle& puzzle);

  private:
    string game;
};

#endif  // PUZZLE_H
