// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "../test/catch.hpp"
#include "streamlineBmsSender.h"

TEST_CASE("Check whether sensor inputs are read from valid txt file") {
  //int CurrentRanges[] = {4,5};
  //int noOfcurrentReadings = sizeof(CurrentRanges)/sizeof(CurrentRanges[0]);
  REQUIRE(readFromSenderTxt() == E_OK);
}
