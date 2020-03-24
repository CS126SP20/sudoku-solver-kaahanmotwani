// Copyright 2020 Kaahan Motwani. All rights reserved.

#include <sudoku/solver.h>

namespace sudoku {


  // UNASSIGNED is used for empty cells in sudoku grid
  #define UNASSIGNED 0

  // N is used for the size of Sudoku grid.
  // Size will be NxN
  #define N 9

  bool SolveSudoku(int grid[N][N]) {
    int row, col;

    // If there is no unassigned location,
    // we are done
    if (!FindUnassignedLocation(grid, row, col))
      return true; // success!

    // consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
      // if looks promising
      if (IsSafe(grid, row, col, num))
      {
        // make tentative assignment
        grid[row][col] = num;

        // return, if success, yay!
        if (SolveSudoku(grid))
          return true;

        // failure, unmake & try again
        grid[row][col] = UNASSIGNED;
      }
    }
    return false; // this triggers backtracking
  }

  /* Searches the grid to find an entry that is
  still unassigned. If found, the reference
  parameters row, col will be set the location
  that is unassigned, and true is returned.
  If no unassigned entries remain, false is returned. */
  bool FindUnassignedLocation(int grid[N][N],
                              int &row, int &col)
  {
    for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
        if (grid[row][col] == UNASSIGNED)
          return true;
    return false;
  }

  bool UsedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
        return true;
    return false;
  }

  bool UsedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
        return true;
    return false;
  }

  /* Returns a boolean which indicates whether
  an assigned entry within the specified 3x3 box
  matches the given number. */
  bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
        if (grid[row + boxStartRow]
            [col + boxStartCol] == num)
          return true;
    return false;
  }

  /* Returns a boolean which indicates whether
  it will be legal to assign num to the given
  row, col location. */
  bool IsSafe(int grid[N][N], int row, int col, int num) {
    /* Check if 'num' is not already placed in
    current row, current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 ,
                      col - col % 3, num) &&
           grid[row][col] == UNASSIGNED;
  }

  /* A utility function to print grid */
  void PrintGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
      for (int col = 0; col < N; col++) {
        std::cout << grid[row][col] << " ";
      }
      std::cout << std::endl;
    }
  }
}  // namespace sudoku

