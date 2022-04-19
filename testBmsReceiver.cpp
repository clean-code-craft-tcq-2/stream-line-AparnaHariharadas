#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Receiver/PerformBmsStatistics.h"

int ReadFromConsoleStub(float* CurrentInAmp, float* TempInDegC)
{
    static int NumberOfSamples = 0;

    *CurrentInAmp = 1.5 + NumberOfSamples;
    *TempInDegC = 10.5 + NumberOfSamples;
    NumberOfSamples++;

    if(NumberOfSamples >= 10)
    {
        NumberOfSamples = 0;
        return 0; // end the loop after 10 samples
    }
    else
    {
        return 2;
    }
    
}

TEST_CASE("Read from the console (Sender) and print statistics for 10 samples")
{
    char printChar[1000];
    unsigned int NumberOfBmsParameters = 2; // Current, Temperature
    BmsStatisticsStructType BmsParam[NumberOfBmsParameters];

    ReadAndPerformBmsStatistics(printChar, BmsParam, NumberOfBmsParameters, (*ReadFromConsoleStub)); //FUT
    
    //Checking parameters after 10 samples are received
    REQUIRE(BmsParam[0].MaxValue == 10.5); //Max current
    REQUIRE(BmsParam[0].MinValue == 1.5); //Min current
    REQUIRE(BmsParam[0].MovingAvg == 8.5); //Avg current
    REQUIRE(BmsParam[1].MaxValue == 19.5); //Max Temperature
    REQUIRE(BmsParam[1].MinValue == 10.5); //Min Temperature
    REQUIRE(BmsParam[1].MovingAvg == 17.5); //Avg Temperature

    char expectedOutput[1000] = {"MinCurrent, MaxCurrent, AvgCurrent, MinTemperature, MaxTemperature, AvgTemperature\n\
1.50, 1.50, 0.00, 10.50, 10.50, 0.00\n\
1.50, 2.50, 0.00, 10.50, 11.50, 0.00\n\
1.50, 3.50, 0.00, 10.50, 12.50, 0.00\n\
1.50, 4.50, 0.00, 10.50, 13.50, 0.00\n\
1.50, 5.50, 3.50, 10.50, 14.50, 12.50\n\
1.50, 6.50, 4.50, 10.50, 15.50, 13.50\n\
1.50, 7.50, 5.50, 10.50, 16.50, 14.50\n\
1.50, 8.50, 6.50, 10.50, 17.50, 15.50\n\
1.50, 9.50, 7.50, 10.50, 18.50, 16.50\n\
1.50, 10.50, 8.50, 10.50, 19.50, 17.50\n"};

    printf("%s\n",printChar);
    printf("%s\n",expectedOutput);
    REQUIRE(strcmp(printChar, expectedOutput) == 0);
}
