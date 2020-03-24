//
// Created by Kaahan Motwani on 3/22/20.
//

#include "sudoku/Puzzle.h"
#include "sudoku/solver.h"

#include <sstream>
#include <vector>
#include <string>



Puzzle::Puzzle() {

}
Puzzle::Puzzle(const string& line) {

}

std::istream& operator>>(std::istream& is, Puzzle puzzle) {
  is >> puzzle.game;
  std::cout << puzzle.game << std::endl;
  for (size_t i = 0; i < puzzle.game.length(); i++) {
    if (puzzle.game[i] == '_') {
      puzzle.game[i] = '0';
    }
  }
  int board[9][9];
  for (size_t i = 0; i < 9; i++) {
    //std::vector<char> row;
    for (size_t j = 0; j < 9; j++) {
      board[i][j] = (int)(puzzle.game[j + (i * 9)]);
      board[i][j] -= '0';

      //row.push_back(puzzle.game[j + (i * 9)]);
    }
    //board.push_back(row);
  }
  std::cout << board[0][0] << std::endl;
  std::cout << puzzle.game[0] << std::endl;
  if (sudoku::SolveSudoku(board)) {
    sudoku::printGrid(board);
  } else {
    std::istringstream unsolvable("Unsolvable");
    //return unsolvable;
  }
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

