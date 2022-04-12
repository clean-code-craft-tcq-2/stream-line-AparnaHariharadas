#include "streamlineBmsSender.h"
senderInputParam processOutputParam;


StreamlineBMSOutput  readFromSenderTxt(string inputFile){
  ifstream inDataFileHandle; 
  string line;
  float Voltage;
  float Temperature;
  int index = 0;
  inDataFileHandle.open(inputFile);
  
  if(!inDataFileHandle)
    return E_NOT_OK;
  
  while ( getline(inDataFileHandle , line)) 
  {
    stringstream   linestream(line);
    linestream >> Voltage >> Temperature;
    processOutputParam.voltage[index] = Voltage;
    processOutputParam.temperature[index] = Temperature;
    index++;
   }
  inDataFileHandle.close();
   return E_OK;
}

void printToConsole(float voltage, float temperature)
{
  cout << voltage <<", " <<temperature <<endl;
}

StreamlineBMSOutput processData(char* copyConsoleOutput)
{
  StreamlineBMSOutput processOutput = readFromSenderTxt("./Sender/streamlineSender.txt");
  for(int loop = 0; loop < MAX_BMS_READ; loop++)
  {
    printToConsole(processOutputParam.voltage[loop], processOutputParam.temperature[loop]);
    strcpy(copyConsoleOutput, to_string(processOutputParam.voltage[loop]) +", " + to_string(processOutputParam.temperature[loop]) + "\n");
    cout << copyConsoleOutput << copyConsoleOutput <<endl;
    
  }
  return processOutput;
}
    
