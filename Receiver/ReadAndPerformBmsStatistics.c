#include "PerformBmsStatistics.h"

int ReadFromConsole(float* CurrentInAmp, float* TempInDegC)
{
   FILE * pSenderFile = NULL;
   char SenderString[1000];
   static int Breaki = 0;

   pSenderFile = fopen ("SenderCheck.txt" , "r");
   if (pSenderFile == NULL)
   {
       perror ("Error opening file");
       return 0;
   }
   else 
   {
     while (fscanf(SenderString, "%f, %f\n", CurrentInAmp, TempInDegC) > 0 )
     {
         printf("%d, %d\n", *CurrentInAmp, *TempInDegC);
         Breaki++;
         if(Breaki >= 5)
         {
            break;
         }
     }
     //else
     {
        fclose (pSenderFile);
        return 0;   
     }
   }
    /*
    char getstringFromConsole[1000];
    gets(getstringFromConsole);
    return sscanf(getstringFromConsole, "%f, %f", CurrentInAmp, TempInDegC);
    */
}

static void computeMin(float value, float* MinValue)
{
    if(value < *MinValue)
    {
        *MinValue = value;
    }
}

static void computeMax(float value, float* MaxValue)
{
    if(value > *MaxValue)
    {
        *MaxValue = value;
    }
}

void shiftValues(float* array)
{
    for(int i = 0; i < (MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG - 1); i++)
    {
        array[i] = array[i+1]; // swap the values (value in 0th index will be discarded)
    }
}

void computeMovingAverage(float value, BmsStatisticsStructType* Param)
{
    double sum = 0.0;
    if(Param->NumberOfValuesInStream >= MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG)
    {
        Param->PreviousValuesForMovingAvg[MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG - 1] = value; // update current value to last index
        for(int i = 0; i < (MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG); i++)
        {
            sum += Param->PreviousValuesForMovingAvg[i];
        }
        Param->MovingAvg = (sum)/MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG;
        shiftValues(Param->PreviousValuesForMovingAvg);
    }
    else
    {
        Param->MovingAvg = 0;
        Param->PreviousValuesForMovingAvg[Param->NumberOfValuesInStream-1] = value;
    }
}

void ResetToDefault(BmsStatisticsStructType* Param)
{
    Param->MaxValue = FLT_MIN;
    Param->MinValue = FLT_MAX;
    Param->MovingAvg = 0;
    Param->NumberOfValuesInStream = 0;

    for(int i = 0; i < (MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG); i++)
    {
        Param->PreviousValuesForMovingAvg[i] = 0;
    }
}

void outputBmsParametersToConsole(char* ToConsole, BmsStatisticsStructType* CurrentParam, BmsStatisticsStructType* TempParam)
{
    char localString[200];
    
    sprintf(localString, "%0.2f, %0.2f, %0.2f, %0.2f, %0.2f, %0.2f\n", CurrentParam->MinValue, CurrentParam->MaxValue, CurrentParam->MovingAvg, 
                                                    TempParam->MinValue, TempParam->MaxValue, TempParam->MovingAvg);
    strcat(ToConsole, localString);
}

void ReadAndPerformBmsStatistics(char* ToConsole, BmsStatisticsStructType* BmsParam, unsigned int NumberOfBmsParameters, int (*ReadInput)(float*, float*))
{
    float BmsValues[NumberOfBmsParameters];
    int NumberOfDataReadFromConsole = 0;
    unsigned int index = 0;
    char localString[200] = {"MinCurrent, MaxCurrent, AvgCurrent, MinTemperature, MaxTemperature, AvgTemperature\n"};

    // Reset the param to default values
    for(index = 0; index < NumberOfBmsParameters; index++)
    {
        ResetToDefault(&BmsParam[index]);
    }
    strcat(ToConsole, localString); // copy the header first

    do{
        NumberOfDataReadFromConsole = (*ReadInput)(&BmsValues[0], &BmsValues[1]);
        for(index = 0; index < NumberOfBmsParameters; index++)
        {
            BmsParam[index].NumberOfValuesInStream++;
            computeMin(BmsValues[index], &BmsParam[index].MinValue);
            computeMax(BmsValues[index], &BmsParam[index].MaxValue);
            computeMovingAverage(BmsValues[index],  &BmsParam[index]);
        }
        outputBmsParametersToConsole(ToConsole, &BmsParam[0], &BmsParam[1]);
    }while(NumberOfDataReadFromConsole > 0);
}
