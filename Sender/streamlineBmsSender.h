#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream> // for ostringstream
#include <string.h>
#include<array>
#include <fstream>
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

StreamlineBMSOutput readFromSenderTxt(int num);
int processData(int lines);
