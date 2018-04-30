/********************************************************************************
 * File: averager.h
 *
 ********************************************************************************/
#include <stdint.h>

/*
 * Abstract data type
 */
typedef struct AveragerStruct* Averager;

/*
 * Create averager
 */
Averager Averager_Create(void);

/*
 * Destroy averager
 */
void Averager_Destroy(Averager a);

/*
 * Push an entry to be averaged
 */
void Averager_Push(Averager a, uint16_t val);

/*
 * Get average
 */
uint16_t Averager_GetAverage(Averager a);
