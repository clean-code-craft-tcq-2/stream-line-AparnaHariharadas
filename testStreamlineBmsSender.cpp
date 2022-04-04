// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/streamlineBmsSender.h"

TEST_CASE("Check whether sensor inputs are read from valid txt file") {
  REQUIRE(readFromSenderTxt("./Sender/streamlineSender.txt") == E_OK);
}

TEST_CASE("Process sensor input and output in CSV format") {
  REQUIRE(processData() == E_OK);
}
