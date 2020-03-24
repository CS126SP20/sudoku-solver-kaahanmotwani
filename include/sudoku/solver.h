// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include <fstream>
#include <iostream>
#include <vector>

namespace sudoku {
  #define N 9

  bool SolveSudoku(int grid[N][N]);
  void printGrid(int grid[N][N]);
}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_

