//
// Created by Kaahan Motwani on 3/22/20.
//

#include "sudoku/Puzzle.h"
#include "sudoku/solver.h"

Puzzle::Puzzle() = default;
int board[9][9];
std::istream &operator>>(std::istream& is, Puzzle puzzle) {
  is >> puzzle.game;
  // Loops through puzzle string and replaces all '_' with '0' chars so that the
  // board is all integers for solver.cc's implementation of solving puzzles.
  for (char & i : puzzle.game) {
    if (i == '_') {
      i = '0';
    }
  }

  // This nested for loop loops through the 81 character string and creates
  // a 9x9 board of integers to store the puzzle
  const int kSqrtBoardSize = 9;
  for (size_t i = 0; i < kSqrtBoardSize; i++) {
    for (size_t j = 0; j < kSqrtBoardSize; j++) {
      board[i][j] = (int) (puzzle.game[j + (i * kSqrtBoardSize)]);
      // The following line subtracts '0' in order to get the correct digit
      // based on character encodings.
      board[i][j] -= '0';
    }
  }

  if (sudoku::SolveSudoku(board)) {
    sudoku::PrintGrid(board);
  } else {
    std::istringstream unsolvable("Unsolvable");
    //return unsolvable;
  }
  return is;
}

std::ostream &operator<<(std::ostream& os, const Puzzle& puzzle) {
  //std::cout << board << std::endl;
  return os;
}


