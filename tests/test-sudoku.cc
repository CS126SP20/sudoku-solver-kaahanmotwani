// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sudoku/solver.h>
#include <sudoku/utils.h>

using utils::ReturnTag;
TEST_CASE("Sanity Check", "[addition]") {
  std::ifstream puzzle_stream("data/faulty");
  REQUIRE(ReturnTag(puzzle_stream) == "#spf2.0");
}


