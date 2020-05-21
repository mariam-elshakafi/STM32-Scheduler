#include "STD_TYPES.h"

#include "RCC.h"
#include "SYSTICK.h"

#include "SCHED.h"
#include "SCHED_CFG.h"

typedef struct
{
  const SysTask_Info *task;
  u32 RemainToExec;
  u32 periodicTimeTicks;
} SysTask;

static SysTask sysTasks[SCHED_MAX_TASK_NUM];
static volatile u8 OS_FLAG = 0;

extern const SysTask_Info sysTasks_cfg[SCHED_MAX_TASK_NUM];

static void SCHED_createTask (const SysTask_Info *task)
{
  if (task)
  {
    sysTasks[task->appTask->priority].task = task;
    sysTasks[task->appTask->priority].RemainToExec = task->firstDelayTicks;
    sysTasks[task->appTask->priority].periodicTimeTicks = (task->appTask->periodicTimeMS)/SCHED_TICK_TIME_MS;
  }
}

static void SCHED_schedule(void)
{
  u32 currentTask = 0;
  for (currentTask = 0; currentTask < SCHED_MAX_TASK_NUM; currentTask++)
  {
    if((sysTasks[currentTask].RemainToExec) == 0)
    {
      (sysTasks[currentTask].task)->appTask->runnable();
      (sysTasks[currentTask].RemainToExec) = sysTasks[currentTask].periodicTimeTicks;
    }
    sysTasks[currentTask].RemainToExec--;
  }
}


static void SCHED_setFlag(void)
{
  OS_FLAG = 1;
}



void SCHED_init(void)
{
  u32 currentTask = 0;
  for (currentTask = 0; currentTask < SCHED_MAX_TASK_NUM; currentTask++)
  {
    SCHED_createTask(&sysTasks_cfg[currentTask]);
  }
  
  RCC_configurePrescalers(RCC_AHB_PRESCALER, SCHED_AHB_PREVAL);
  SYSTICK_init();
  u32 prescalerVal = SCHED_AHB_PREVAL;
  u32 clockDiv = 1;
  if (prescalerVal != RCC_AHB_NDIVIDED)
  {
    if (prescalerVal <= RCC_AHB_DIV_16)
    {
      prescalerVal >>= 0x4;
      prescalerVal &= 0x7;
      prescalerVal++;
      clockDiv = (1 << prescalerVal);
    }
    else
    {
      prescalerVal >>= 0x4;
      prescalerVal &= 0x7;
      prescalerVal += 2;
      clockDiv = (1 << prescalerVal);
    }
  }
  u32 AHB_clock = SCHED_AHB_CLOCK_HZ / clockDiv;
  SYSTICK_setTime(SCHED_TICK_TIME_MS, AHB_clock);
  SYSTICK_setCallbackFcn(SCHED_setFlag);
  SYSTICK_start();
}



void SCHED_start(void)
{
  while(1)
  {
    if(OS_FLAG)
    {
      OS_FLAG = 0;
      SCHED_schedule();
    }
  }
}
