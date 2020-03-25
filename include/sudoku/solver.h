// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include <fstream>
#include <iostream>
#include <vector>

#define kRowColSize 9
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

namespace sudoku {
  using std::vector;

  /**
   * This function finds an entry in grid that is still unassigned
   *
   * @param grid the 9x9 integer array representing the board
   * @param row the index of the row in the grid
   * @param col the index of the col in the grid
   * @return bool of if there are assigned entries left on the board
   */
  bool FindUnassignedLocation(int grid[kRowColSize][kRowColSize],
      int &row, int &col);

  /**
   * Checks whether it will be legal to assign integer to the given row, col
   *
   * @param grid the 9x9 integer array representing the board
   * @param row the index of the row in the grid
   * @param col the index of the column in the grid
   * @param num the number we are trying to assign
   * @return a bool of if it is safe to assign num to index of the grid
   */
  bool IsSafe(int grid[kRowColSize][kRowColSize], int row, int col, int num);

  /**
   * Takes a partially filled-in grid and attempts to assign values to all
   * unassigned locations in such a way to meet the requirements for Sudoku
   * solution (non-duplication across rows, columns, and boxes).
   * Algorithm for solving Sudoku puzzle below derived from:
   * https://www.geeksforgeeks.org/sudoku-backtracking-7/
   *
   * @param grid the 9x9 integer array representing the board
   * @return a bool indicating if solving the Sudoku board was a success or not
   */
  bool SolveSudoku(int grid[kRowColSize][kRowColSize]);

  /**
   * Returns a boolean which indicates whether an assigned entry in the
   * specified row matches the given number.
   *
   * @param grid the 9x9 integer array representing the board
   * @param row the index of the row in the grid
   * @param num the number we are trying to assign
   * @return a bool of if num was used in the row
   */
  bool UsedInRow(int grid[kRowColSize][kRowColSize], int row, int num);

  /**
   * Returns a boolean which indicates whether an assigned entry in the
   * specified column matches the given number.
   *
   * @param grid the 9x9 integer array representing the board
   * @param col the index of the column in the grid
   * @param num the number we are trying to assign
   * @return a bool of if num was used in the column
   */
  bool UsedInCol(int grid[kRowColSize][kRowColSize], int col, int num);

  /**
   * Returns a boolean which indicates whether an assigned entry in the
   * specified box (3x3) matches the given number.
   *
   * @param grid the 9x9 integer array representing the board
   * @param boxStartRow the index of the start of the row in the box
   * @param boxStartCol the index of the start of the column in the box
   * @param num given integer that should match the assigned integer
   * @return a boolean of whether the assigned entry in a box matches num
   */
  bool UsedInBox(int grid[kRowColSize][kRowColSize], int boxStartRow,
      int boxStartCol, int num);

}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_

