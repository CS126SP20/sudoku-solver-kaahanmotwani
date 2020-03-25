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
using std::ostream;

class Puzzle {
  public:
    /**
    * Creates an empty constructor for a Puzzle object.
    */
    Puzzle();
    /**
     * This is the overloaded operator function for input that calls on methods in solver.cc which solve the puzzle
     * using an algorithm.
     *
     * @param is the given input istream that contains an unsolved puzzle
     * @param puzzle The passed in puzzle parameter
     * @return the istream
     */
    friend std::istream &operator>>(istream& is, Puzzle puzzle);

    /**
     * This is the overloaded operator function for output that allows the puzzle to be printed.
     *
     * @param os The passed in parameter of type ostream that gets a solved
     * puzzle loaded into it
     * @param puzzle The passed in Puzzle parameter
     * @return a solved puzzle that can be printed using overloading
     */
    friend std::ostream &operator<<(std::ostream& os, const Puzzle& puzzle);

  private:
    /**
     * Represents each unsolved game.
     */
    string game;
};

#endif  // PUZZLE_H
