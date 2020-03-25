// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sudoku/solver.h>
#include <sudoku/utils.h>

using utils::ReturnTag;
using utils::ReturnAndPrintSolvedPuzzle;
using utils::ContainsValidCharacters;

TEST_CASE("Wrong tag", "[faulty-file]") {
  std::ifstream puzzle_stream("data/faulty_tag.spf");
  REQUIRE(ReturnTag(puzzle_stream) == "#spf2.0");
}

TEST_CASE("Empty tag", "[faulty-file]") {
  std::ifstream puzzle_stream("../data/empty_tag.spf");
  REQUIRE(ReturnTag(puzzle_stream).empty());
}

/**
 * The solve-puzzle tag groups tests of likely inputs
 */
TEST_CASE("Correct tag", "[solve-puzzle]") {
  std::ifstream puzzle_stream("data/simple2.spf");
  REQUIRE(ReturnTag(puzzle_stream) == "#spf1.0");
}

/**
 * Tests that a regular puzzle can be solved, which shows if spf file parsing
 * is working and that the algorithm is working.
 */
TEST_CASE("Solve Regular Puzzle", "[solve-puzzle]") {
  std::ifstream puzzle_stream("data/simple2.spf");
  string puz = "___8_5____3__6___7_9___38___4795_3______71_9____"
               "2__5__1____248___9____5______6___";
  string solution = "71482593653846912769271384524795836185367129496123457817"
                    "6592483389147652425386719\n";
  REQUIRE(ReturnAndPrintSolvedPuzzle(puz) == solution);
}

TEST_CASE("Expected characters", "[solve-puzzle]") {
  string puz = "___8_5____3__6___7_9___38___4795_3______71_9____"
               "2__5__1____248__";
  REQUIRE(ContainsValidCharacters(puz));
}

TEST_CASE("Too many characters", "[faulty-puzzle]") {
  string puz = "___8_5____3__6___7_9___38___4795_3______71_9____"
               "2__5__1____248___9____5______6___________";
  REQUIRE(ReturnAndPrintSolvedPuzzle(puz).empty());
}

TEST_CASE("Too few characters", "[faulty-puzzle]") {
  string puz = "___8_5____3__6___7_9___38___4795_3______71_9____"
               "2__5__1____248__";
  REQUIRE(ReturnAndPrintSolvedPuzzle(puz).empty());
}

TEST_CASE("Unexpected characters", "[faulty-puzzle]") {
  string puz = "___8_5____k__6___7_9___38___4795_3______71_9____"
               "2__5__1____248__";
  REQUIRE(!ContainsValidCharacters(puz));
}

