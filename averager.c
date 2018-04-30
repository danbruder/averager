/********************************************************************************
 * File: averager.c
 *
 ********************************************************************************/
#include <stdlib.h>
#include "averager.h"

#define SIZE 16
#define SHIFT 4

typedef struct  AveragerStruct{
  uint16_t buffer[SIZE];
  uint8_t newest_index;
  uint8_t oldest_index;
  uint32_t total;
} AveragerStruct;

Averager Averager_Create(){
  uint8_t i;
  Averager a = malloc(sizeof(AveragerStruct));

  for(i = 0; i < SIZE; i++)
  {
    a->buffer[i] = 0;
  }

  a->newest_index = 0;
  a->oldest_index = 1;
  a->total = 0;
  return a;
}

void Averager_Destroy(Averager a){
  free(a);
}

void Averager_Push(Averager a, uint16_t val){
  a->buffer[a->newest_index] = val;

  if(a->newest_index < (SIZE - 1))
  {
    a->newest_index++;
  }
  else
  {
    a->newest_index = 0;
  }

  if(a->oldest_index < (SIZE - 1))
  {
    a->oldest_index++;
  }
  else
  {
    a->oldest_index = 0;
  }

  a->total = a->total + val - a->buffer[a->oldest_index];
}

uint16_t Averager_GetAverage(Averager a)
{
  return a->total >> SHIFT;
}
