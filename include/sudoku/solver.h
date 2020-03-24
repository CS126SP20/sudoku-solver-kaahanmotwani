// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include <fstream>
#include <iostream>
#include <vector>

namespace sudoku {
  using std::vector;

  #define N 9

  /**
   * This function finds an entry in grid that is still unassigned
   * @param grid
   * @param row
   * @param col
   * @return
   */
  bool FindUnassignedLocation(int grid[N][N], int &row, int &col);

  /**
   * Checks whether it will be legal to assign num to the given row, col
   *
   * @param grid
   * @param row
   * @param col
   * @param num
   * @return
   */
  bool IsSafe(int grid[N][N], int row, int col, int num);



  /**
   * Takes a partially filled-in grid and attempts to assign values to all
   * unassigned locations in such a way to meet the requirements for Sudoku
   * solution (non-duplication across rows, columns, and boxes)
   *
   * @param grid
   * @return
   */
  bool SolveSudoku(int grid[N][N]);

  /**
   * Returns a boolean which indicates whether an assigned entry in the
   * specified row matches the given number.
   *
   * @param grid
   * @param row
   * @param num
   * @return
   */
  bool UsedInRow(int grid[N][N], int row, int num);

  /**
   *
   * @param grid
   * @param col
   * @param num
   * @return
   */
  bool UsedInCol(int grid[N][N], int col, int num);

  /**
   *
   * @param grid
   * @param boxStartRow
   * @param boxStartCol
   * @param num
   * @return
   */
  bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);

  void printGrid(int grid[N][N]);
}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_

