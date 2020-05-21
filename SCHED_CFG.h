typedef struct
{
  const Task *const appTask;
  u32 firstDelayTicks;
} SysTask_Info;


#define SCHED_MAX_TASK_NUM 1

/* Masks for clock configuration */
#define SCHED_AHB_PREVAL RCC_AHB_NDIVIDED
#define SCHED_AHB_CLOCK_HZ        8000000
#define SCHED_TICK_TIME_MS              1
