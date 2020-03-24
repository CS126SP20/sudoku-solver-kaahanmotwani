// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include <fstream>
#include <iostream>
#include <vector>

namespace sudoku {
  #define N 9

  bool SolveSudoku(std::vector<std::vector<char>> board);
  void printGrid(std::vector<std::vector<char>> board);
}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_

