// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#include <sudoku/solver.h>

#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char** argv) {
  //std::ifstream puzzle_stream;
  if (argc > 1) {
    std::ifstream puzzle_stream(argv[1]);

    if (puzzle_stream.fail()) {
      // Handle read error.
    }

    std::istream& input_stream = puzzle_stream;

    std::string tag;
    input_stream >> tag;

//    std::string line;
//    while (std::getline(puzzle_stream, line))
//    {
//      std::istringstream iss(line);
//      int a, b;
//      if (!(iss >> a >> b)) { break; } // error
//
//      // process pair (a,b)
//    }

  } else {
    printf("You need to provide a sudoku file through command line arguments!");
    exit(0);
  }

  return 0;
}
