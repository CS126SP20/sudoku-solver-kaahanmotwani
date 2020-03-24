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
    /**
    * Creates an empty constructor for a Puzzle object.
    */
    Puzzle();
    /**
     *
     * @param is
     * @param puzzle
     * @return
     */
    friend istream& operator>>(istream& is, Puzzle puzzle);
    /**
     *
     * @param os
     * @param puzzle
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os, const Puzzle& puzzle);

  private:
    /**
     * efw
     */
    string game;
};

#endif  // PUZZLE_H
