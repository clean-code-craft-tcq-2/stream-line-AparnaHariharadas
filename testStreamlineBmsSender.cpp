// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/streamlineBmsSender.h"

TEST_CASE("Check whether sensor inputs are read from valid txt file") {
  //int CurrentRanges[] = {4,5};
  //int noOfcurrentReadings = sizeof(CurrentRanges)/sizeof(CurrentRanges[0]);
  REQUIRE(readFromSenderTxt("Sender/streamlineSender.txt") == E_OK);
  //REQUIRE(processData() == 1);
}
