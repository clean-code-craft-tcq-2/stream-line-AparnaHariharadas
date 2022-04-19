#include "Receiver/PerformBmsStatistics.h"


int main()
{
  char printChar[1000];
  unsigned int NumberOfBmsParameters = 2; // Current, Temperature
  BmsStatisticsStructType BmsParam[NumberOfBmsParameters];

  ReadAndPerformBmsStatistics(printChar, BmsParam, NumberOfBmsParameters, (*ReadFromConsole));
  printf("%s",printChar);
  
  return 0;
}
