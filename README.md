# STM32-Scheduler
This is an implementation for a non-preemptive scheduler on ARM STM32F103xx microcontroller

## How to use

1. This scheduler is implemented using SysTick and RCC drivers in [my drivers repo](https://github.com/mariam-elshakafi/STM32-Drivers)
So, they should be included in the project. Also, STD_TYPES.h must be included.

2. You can include SCHED.h in any other module, create a task as follows:

> Task t1 = {.runnable = function, .periodicTimeMS = PERIOD_IN_MS, .priority = PERIORITY};

Note that PERIORITY should be a number between (0) and (SCHED_MAX_TASK_NUM - 1).

3. The created task should be included in SCHED_CFG.c

4. SCHED_CFG.h should be edited with proper clock configurations & proper task count.