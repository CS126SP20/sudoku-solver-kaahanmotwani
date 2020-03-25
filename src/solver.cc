// Copyright 2020 Kaahan Motwani. All rights reserved.

#include <sudoku/solver.h>

namespace sudoku {

  bool SolveSudoku(int grid[kRowColSize][kRowColSize]) {
    int row, col;

    // If there is no unassigned location, puzzle is solved
    if (!FindUnassignedLocation(grid, row, col))
      return true;

    for (int num = 1; num <= 9; num++) {
      if (IsSafe(grid, row, col, num)) {
        // make tentative assignment
        grid[row][col] = num;
        // return, if success, the puzzle is solved
        if (SolveSudoku(grid))
          return true;
        // failure, undo the assignment & re-attempt
        grid[row][col] = UNASSIGNED;
      }
    }
    return false;
  }

  bool FindUnassignedLocation(int grid[kRowColSize][kRowColSize],
                              int &row, int &col) {
    for (row = 0; row < kRowColSize; row++)
      for (col = 0; col < kRowColSize; col++)
        if (grid[row][col] == UNASSIGNED)
          return true;
    return false;
  }

  bool UsedInRow(int grid[kRowColSize][kRowColSize], int row, int num) {
    for (int col = 0; col < kRowColSize; col++)
      if (grid[row][col] == num)
        return true;
    return false;
  }

  bool UsedInCol(int grid[kRowColSize][kRowColSize], int col, int num) {
    for (int row = 0; row < kRowColSize; row++)
      if (grid[row][col] == num)
        return true;
    return false;
  }

  bool UsedInBox(int grid[kRowColSize][kRowColSize], int boxStartRow,
      int boxStartCol, int num) {
    for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
        if (grid[row + boxStartRow]
            [col + boxStartCol] == num)
          return true;
    return false;
  }

  bool IsSafe(int grid[kRowColSize][kRowColSize], int row, int col, int num) {
    // Checks if 'num' is not already placed in
    // current row, current column and current 3x3 box
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 ,
                      col - col % 3, num) &&
           grid[row][col] == UNASSIGNED;
  }

}  // namespace sudoku

