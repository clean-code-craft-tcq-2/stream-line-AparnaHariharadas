#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include "Receiver/PerformBmsStatistics.h",

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
    unsigned int SizeofDataRead = 0;

    ReadAndPerformBmsStatistics(printChar, BmsParam, NumberOfBmsParameters, (*ReadFromConsoleStub)); //FUT
    
    //Checking parameters after 10 samples are received
    REQUIRE(BmsParam[0].MaxValue == 10.5); //Max current
    REQUIRE(BmsParam[0].MinValue == 1.5); //Min current
    REQUIRE(BmsParam[0].MovingAvg == 8.5); //Avg current
    REQUIRE(BmsParam[1].MaxValue == 19.5); //Max Temperature
    REQUIRE(BmsParam[1].MinValue == 10.5); //Min Temperature
    REQUIRE(BmsParam[1].MovingAvg == 17.5); //Avg Temperature

    char expectedOutput[1000] = {"MinCurrent, MaxCurrent, AvgCurrent, MinTemperature, MaxTemperature, AvgTemperature\n\
                                    1.5, 1.5, 0, 10.5, 10.5, 0\n\
                                    1.5, 2.5, 0, 10.5, 11.5, 0\n\
                                    1.5, 3.5, 0, 10.5, 12.5, 0\n\
                                    1.5, 4.5, 0, 10.5, 13.5, 0\n\
                                    1.5, 5.5, 3.5, 10.5, 14.5, 4.3\n\
                                    1.5, 6.5, 5.1, 10.5, 15.5, 5.7\n\
                                    1.5, 7.5, 6.3, 10.5, 16.5, 6.7\n\
                                    1.5, 8.5, 7.3, 10.5, 17.5, 7.7\n\
                                    1.5, 9.5, 8.3, 10.5, 18.5, 8.7\n\
                                    1.5, 10.5, 9.3, 10.5, 19.5, 9.7\n"};
    REQUIRE(printChar);
}