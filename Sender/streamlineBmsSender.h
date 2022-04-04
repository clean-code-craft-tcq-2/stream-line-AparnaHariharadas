#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string.h>
#include<array>
#include <fstream>
using namespace std;
#define MAX_BMS_READ 50

typedef enum
{
	E_NOT_OK,
	E_OK
}StreamlineBMSOutput;

typedef struct batteryParam
{
  float voltage[MAX_BMS_READ];
  float temperature[MAX_BMS_READ];
}senderInputParam;

StreamlineBMSOutput readFromSenderTxt(string inputFile);
StreamlineBMSOutput processData();
