#include "unity.h"
#include "averager.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Averager_CanCreate(void)
{
  Averager a = Averager_Create();
}

void test_Averager_CanDestroy(void)
{
  TEST_IGNORE_MESSAGE("Inspect creation to ensure finite calls to malloc"); 
}

void test_Averager_CanPushElements(void)
{
  Averager a = Averager_Create();
  Averager_Push(a, 20);
  Averager_Destroy(a);
}

void test_Averager_CanGetAverage(void)
{
  Averager a = Averager_Create();

  for(int i = 0; i < 16; i++){
    Averager_Push(a, 20 + i);
  }

  TEST_ASSERT_EQUAL(24, Averager_GetAverage(a));

  Averager_Push(a, 0);
  TEST_ASSERT_EQUAL(23, Averager_GetAverage(a));

  Averager_Push(a, 34);
  TEST_ASSERT_EQUAL(24, Averager_GetAverage(a));

  Averager_Push(a, 100);
  TEST_ASSERT_EQUAL(29, Averager_GetAverage(a));

  Averager_Push(a, 0);
  TEST_ASSERT_EQUAL(27, Averager_GetAverage(a));
}
