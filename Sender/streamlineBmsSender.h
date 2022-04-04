#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


typedef enum
{
	E_NOT_OK,
	E_OK
}StreamlineBMSOutput;

typedef struct batteryParam
{
  float voltage;
  float temperature;
}senderInputParam;

StreamlineBMSOutput readFromSenderTxt(string inputFileName);
