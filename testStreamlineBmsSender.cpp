// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/streamlineBmsSender.h"

TEST_CASE("Check whether sensor inputs are read from valid txt file") {
  REQUIRE(readFromSenderTxt("./Sender/streamlineSender.txt") == E_OK);
  REQUIRE(readFromSenderTxt("./Sender/lineSender.txt") == E_NOT_OK);
}

TEST_CASE("Process sensor input and output in CSV format") {
  char cpyConsoleData[200];
  REQUIRE(processData(cpyConsoleData) == E_OK);
}

TEST_CASE("check if the output is imn CSV format")
{
  char cpyConsoleData[200];
  char resultConsoleData[200];
  char ExpectedOutput[] = {"30, 90\n45, 60\n"};
  int NumOfValuesToBeGenerated = 10;

  processData(cpyConsoleData);
  strycpy(resultConsoleData,cpyConsoleData[0]+cpyConsoleData[1]);
  REQUIRE(strcmp(resultConsoleData, cpyConsoleData) == 0);
}
