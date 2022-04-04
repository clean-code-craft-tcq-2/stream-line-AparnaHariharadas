#include "streamlineBmsSender.h"
//using ifstream;


StreamlineBMSOutput  readFromSenderTxt(int num){
  ifstream inDataFileHandle; 
  string line;
  senderInputParam inputParameters;
  inDataFileHandle.open("streamlineSender.txt");
   if(!inDataFileHandle)
      return E_NOT_OK;
  while ( getline(inDataFileHandle , line)) {
    stringstream   linestream(line);
    //std::getline(linestream, data, '\t');  // read up-to the first tab (discard tab).
    linestream >> inputParameters.voltage >> inputParameters.temperature;
    cout << inputParameters.voltage << inputParameters.temperature << num <<endl;
   }
   return E_OK;
}

int processData(int lines)
{
  (void)readFromSenderTxt(lines);
  return 1;
}
     
