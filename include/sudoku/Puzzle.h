//
// Created by Kaahan Motwani on 3/22/20.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <istream>
#include <sstream>
#include <string>

using std::istream;
using std::string;

class Puzzle {
  public:
  Puzzle();
   friend istream& operator>>(istream& is, Puzzle puzzle);
    friend std::ostream& operator<<(std::ostream& os, const Puzzle& puzzle);

  private:
    string game;
};

#endif  // PUZZLE_H
