#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

#define COLUMN_INDEX_FOR_CURRENT            0
#define COLUMN_INDEX_FOR_TEMPERATURE        1
#define MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG 5

typedef struct{
    float PreviousValuesForMovingAvg[MIN_NUMBER_OF_VALUES_FOR_MOVING_AVG];
    float MaxValue;
    float MinValue;
    float MovingAvg;
    int NumberOfValuesInStream;
}BmsStatisticsStructType;

extern void shiftValues(float* array);
extern void computeMovingAverage(float value, BmsStatisticsStructType* Param);
extern void ResetToDefault(BmsStatisticsStructType* Param);
extern void ReadAndPerformBmsStatistics(char* ToConsole, BmsStatisticsStructType* BmsParam, unsigned int NumberOfBmsParameters, int (*ReadInput)(float*, float*));