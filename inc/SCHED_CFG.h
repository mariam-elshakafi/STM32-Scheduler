/**
 * @file SCHED_CFG.h
 * @author Mariam El-Shakafi (mariam.elshakafi@gmail.com)
 * @brief This is the header to configuration file for the scheduler
 * @version 0.1
 * @date 2020-04-7
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SCHED_CFG_H
#define SCHED_CFG_H

typedef struct
{
  const Task *const appTask;
  u32 firstDelayTicks;
} SysTask_Info;

/*** Task count configuration ***/

#define SCHED_MAX_TASK_NUM 1

/*** Clock & Tick configuration ***/

#define SCHED_AHB_PREVAL RCC_AHB_NDIVIDED
#define SCHED_AHB_CLOCK_HZ        8000000
#define SCHED_TICK_TIME_MS              1

#endif