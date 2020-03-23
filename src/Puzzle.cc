//
// Created by Kaahan Motwani on 3/22/20.
//

#include "sudoku/Puzzle.h"
#include <sstream>

Puzzle::Puzzle() {

}
Puzzle::Puzzle(const string& line) {

}
std::istream& operator>>(std::istream& is, Puzzle puzzle) {
  is >> puzzle.game;
  return is;
}
std::istream& operator<<(std::ostream& os, const Puzzle& puzzle) {

}
//  std::istream& operator>> (std::istream& is, Date dt) {
//    is>> dt.mo>> dt.da>> dt.yr;
//    return is;
//  }
//  std::istream& operator>>(std::istream is, Puzzle puzzle) {
//
//  }

//  void createPuzzleList() {
//    std::string line;
//    while (std::getline(puzzle_stream, line)) {
//      if (line.length() == 81) {
//        std::istringstream str(line);
//        Puzzle p;
//        str >> p;
//
//      }
//      //      Puzzle puzzle;
//      //      line >> puzzle;  // Initialize the puzzle
//      //      std::cout << puzzle << std::endl;  // Print the solved puzzle
//    }
//  }

