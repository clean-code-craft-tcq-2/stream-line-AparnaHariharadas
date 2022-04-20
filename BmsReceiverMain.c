#include "Receiver/PerformBmsStatistics.h"


int main()
{
  char printChar[1000];
  unsigned int NumberOfBmsParameters = 2; // Current, Temperature
  BmsStatisticsStructType BmsParam[NumberOfBmsParameters];

  FILE * ptrToTestFile = NULL;
  ptrToTestFile = fopen("SenderCheck.txt","r");
  ReadAndPerformBmsStatistics(ptrToTestFile, printChar, BmsParam, NumberOfBmsParameters);
  printf("%s",printChar);
  
  return 0;
}
