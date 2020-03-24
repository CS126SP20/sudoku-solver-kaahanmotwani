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
int board[9][9];
std::istream& operator>>(std::istream& is, Puzzle puzzle) {
  is >> puzzle.game;
  std::cout << puzzle.game << std::endl;
  for (size_t i = 0; i < puzzle.game.length(); i++) {
    if (puzzle.game[i] == '_') {
      puzzle.game[i] = '0';
    }
  }
  const int kSqrtBoardSize = 9;
  for (size_t i = 0; i < kSqrtBoardSize; i++) {
    for (size_t j = 0; j < kSqrtBoardSize; j++) {
      board[i][j] = (int)(puzzle.game[j + (i * 9)]);
      board[i][j] -= '0';
    }
  }
//  std::cout << board[0][0] << std::endl;
//  std::cout << puzzle.game[0] << std::endl;
  if (sudoku::SolveSudoku(board)) {
    sudoku::printGrid(board);
    //board >> puzzle;
  } else {
    std::istringstream unsolvable("Unsolvable");
    //return unsolvable;
  }
  return is;
}

std::istream& operator<<(std::ostream& os, const Puzzle& puzzle) {

}


