#include <stdio.h>
#include <assert.h>
#include "checker.h"

const SensType SensParam[TOTAL_SENS_NO] =
    {
        {{0, 45}, "Temperature out of range!\n"},
        {{20, 80},"State of Charge out of range!\n"},
        {{0.8, MAX_CUR_LMT},"Charge Rate out of range!\n"}};

int ChkUprLim(float Val, float UprBound)
{
  if (Val > UprBound)
  {
    return 0;
  }
  return 1;
}

int ChkLwrLim(float Val, float LwrBound)
{
  if (Val < LwrBound)
  {
    return 0;
  }
  return 1;
}

// Checking upper and lower limit
int CheckRange(float Val, Range Bound)
{
  return (ChkUprLim(Val, Bound.Upr) || ChkLwrLim(Val, Bound.Lwr));
}

int batteryIsOk(float *BattParam)
{
  for (size_t i = 0; i < TOTAL_SENS_NO; i++)
  { 
    if (!CheckRange(*BattParam, SensParam[i].Lim))
    {
      printf("%s \n",SensParam[i].ErrMsg);
      return 0;
    }
    BattParam++;
  }
  return 1;
}

int main()
{
  float BattParamTst1[TOTAL_SENS_NO] = {25, 70, 0.7};
  float BattParamTst2[TOTAL_SENS_NO] = {50, 85, 0};


  assert(batteryIsOk(BattParamTst1));
  assert(!batteryIsOk(BattParamTst2));
}
