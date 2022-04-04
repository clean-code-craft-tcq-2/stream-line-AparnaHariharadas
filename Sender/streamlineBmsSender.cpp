#include "streamlineBmsSender.h"



StreamlineBMSOutput  readFromSenderTxt(){
  ifstream inDataFileHandle; 
  string line;
  senderInputParam inputParameters;
  float Voltage;
  float Temperature;
  inDataFileHandle.open("./Sender/streamlineSender.txt");
   if(!inDataFileHandle)
      return E_NOT_OK;
  while ( getline(inDataFileHandle , line)) {
    stringstream   linestream(line);
    //std::getline(linestream, data, '\t');  // read up-to the first tab (discard tab).
    linestream >> Voltage >> Temperature;
    inputParameters.voltage = Voltage;
    inputParameters.temperature = Temperature;
    cout <<inputParameters.voltage <<", " <<inputParameters.temperature <<endl;
   
   }
  inDataFileHandle.close();
   return E_OK;
}

int processData()
{
  StreamlineBMSOutput processOutput;
  processOutput = readFromSenderTxt();
  return 1;
}
     
