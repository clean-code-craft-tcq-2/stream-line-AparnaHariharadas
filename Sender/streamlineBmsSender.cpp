#include "streamlineBmsSender.h"
#include <sstream> // for ostringstream
#include <string.h>
#include<array>
#include <fstream>
using std::ifstream;



StreamlineBMSOutput readFromSenderTxt(string inputFileName){
  ifstream inDataFileHandle; 
  string line;
  senderInputParam inputParameters;
  inDataFileHandle.open(inputFileName);
   if(!inDataFileHandle)
      return E_NOT_OK;
  while ( getline(inDataFileHandle , line)) {
    stringstream   linestream(line);
    //std::getline(linestream, data, '\t');  // read up-to the first tab (discard tab).
    linestream >> inputParameters.voltage >> inputParameters.temperature;
    cout << inputParameters.voltage << inputParameters.temperature <<endl;
   }
   return E_OK;
}
    
     
