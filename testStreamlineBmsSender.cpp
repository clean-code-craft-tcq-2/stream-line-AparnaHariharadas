// Test driven Development. -> Define the testcase before implementation.
#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Sender/streamlineBmsSender.h"

TEST_CASE("Check whether sensor inputs are read from valid txt file") {
  REQUIRE(readFromSenderTxt("./Sender/streamlineSender.txt") == E_OK);
  REQUIRE(readFromSenderTxt("./Sender/lineSender.txt") == E_NOT_OK);
}

TEST_CASE("Process sensor input and output in CSV format") {
  REQUIRE(processData(cpyConsoleData) == E_OK);
}

/*TEST_CASE("check if the output is in CSV format")
{
  char cpyConsoleData[5000];
  //char resultConsoleData[2];
  //char ExpectedOutput[]= "30, 90\n";
   REQUIRE(processData(cpyConsoleData) == E_OK);
  //strcpy(resultConsoleData,cpyConsoleData[0]);
  //REQUIRE(strcmp(resultConsoleData, ExpectedOutput) == 0);
}*/
