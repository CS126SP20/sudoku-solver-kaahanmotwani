// Copyright 2020 Kaahan Motwani. All rights reserved.

#include <sudoku/solver.h>



namespace sudoku {

using std::vector;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// This function finds an entry in grid
// that is still unassigned
bool FindUnassignedLocation(vector<vector<char>> board,
                            int &row, int &col);

// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(vector<vector<char>> board, int row,
            int col, int num);

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool SolveSudoku(vector<vector<char>> board)
{
  int row, col;

  // If there is no unassigned location,
  // we are done
  if (!FindUnassignedLocation(board, row, col))
    return true; // success!

  // consider digits 1 to 9
  for (int num = 1; num <= 9; num++)
  {
    // if looks promising
    if (isSafe(board, row, col, num))
    {
      // make tentative assignment
      board[row][col] = num;

      // return, if success, yay!
      if (SolveSudoku(board))
        return true;

      // failure, unmake & try again
      board[row][col] = UNASSIGNED;
    }
  }
  return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is
still unassigned. If found, the reference
parameters row, col will be set the location
that is unassigned, and true is returned.
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(vector<vector<char>> board,
                            int &row, int &col)
{
  for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
      if (board[row][col] == UNASSIGNED)
        return true;
  return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified row matches
the given number. */
bool UsedInRow(vector<vector<char>> board, int row, int num)
{
  for (int col = 0; col < N; col++)
    if (board[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool UsedInCol(vector<vector<char>> board, int col, int num)
{
  for (int row = 0; row < N; row++)
    if (board[row][col] == num)
      return true;
  return false;
}

/* Returns a boolean which indicates whether
an assigned entry within the specified 3x3 box
matches the given number. */
bool UsedInBox(vector<vector<char>> board, int boxStartRow,
               int boxStartCol, int num)
{
  for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
      if (board[row + boxStartRow]
          [col + boxStartCol] == num)
        return true;
  return false;
}

/* Returns a boolean which indicates whether
it will be legal to assign num to the given
row, col location. */
bool isSafe(vector<vector<char>> board, int row,
            int col, int num)
{
  /* Check if 'num' is not already placed in
  current row, current column and current 3x3 box */
  return !UsedInRow(board, row, num) &&
         !UsedInCol(board, col, num) &&
         !UsedInBox(board, row - row % 3 ,
                    col - col % 3, num) &&
         board[row][col] == UNASSIGNED;
}

/* A utility function to print grid */
void printGrid(vector<vector<char>> board)
{
  for (int row = 0; row < N; row++)
  {
    for (int col = 0; col < N; col++)
      std::cout << board[row][col] << " ";
    std::cout << std::endl;
  }
}
}  // namespace sudoku

