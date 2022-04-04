#include "streamlineBmsSender.h"
senderInputParam processOutputParam;


StreamlineBMSOutput  readFromSenderTxt(){
  ifstream inDataFileHandle; 
  string line;
  float Voltage;
  float Temperature;
  int index = 0;
  inDataFileHandle.open("./Sender/streamlineSender.txt");
   if(!inDataFileHandle)
      return E_NOT_OK;
  while ( getline(inDataFileHandle , line)) {
    stringstream   linestream(line);
    linestream >> Voltage >> Temperature;
    processOutputParam.voltage[index] = Voltage;
    processOutputParam.temperature[index] = Temperature;
    index++;
   }
  inDataFileHandle.close();
   return E_OK;
}

void printToConsole(float voltage, float temperature){
  cout << voltage <<", " <<temperature <<endl;
}

StreamlineBMSOutput processData()
{
  processOutput = readFromSenderTxt();
  for(int loop = 0; loop < MAX_BMS_READ; loop++)
  {
    printToConsole(processOutputParam.voltage[loop], processOutputParam.temperature[loop]);
    
  }
  return processOutput;
}
    
