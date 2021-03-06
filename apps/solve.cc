// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#include <sudoku/utils.h>

int main(int argc, char** argv) {
  if (argc > 1) {
    std::ifstream puzzle_stream(argv[1]);
    if (puzzle_stream.fail()) {
      // Handle read error
      throw std::invalid_argument("The file could not open!");
    }
    utils::ReturnTag(puzzle_stream);
  } else {
    cout << "You need to provide a Sudoku file through command line "
            "arguments!"
         << endl;
    exit(0);
  }

  return 0;
}








