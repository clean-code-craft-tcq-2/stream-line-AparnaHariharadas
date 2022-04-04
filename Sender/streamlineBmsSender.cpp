#include "streamlineBmsSender.h"
using ifstream;


StreamlineBMSOutput  readFromSenderTxt(string inputFile){
  ifstream inDataFileHandle; 
  string line;
  senderInputParam inputParameters;
  float Voltage, Temperature
  inDataFileHandle.open(inputFile);
   if(!inDataFileHandle)
      return E_NOT_OK;
  while ( getline(inDataFileHandle , line)) {
    stringstream   linestream(line);
    //std::getline(linestream, data, '\t');  // read up-to the first tab (discard tab).
    linestream >> Voltage >> Temperature;
    linestream >> inputParameters.voltage >> inputParameters.temperature;
    cout << inputParameters.voltage << inputParameters.temperature << num <<endl;
    cout << "VOLTTEMP" <<Voltage << Temperature << num <<endl;
   }
   return E_OK;
}

int processData()
{
  (void)readFromSenderTxt(lines);
  return 1;
}
     
