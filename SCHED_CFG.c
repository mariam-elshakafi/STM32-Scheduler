#include "STD_TYPES.h"

#include "SCHED.h"
#include "SCHED_CFG.h"

extern Task t1;
const SysTask_Info sysTasks_cfg[SCHED_MAX_TASK_NUM] = {
                                                   {.appTask = &t1,.firstDelayTicks = 0},
                                                  };
