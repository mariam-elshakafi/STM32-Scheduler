/**
 * @file SCHED_CFG.c
 * @author Mariam El-Shakafi (mariam.elshakafi@gmail.com)
 * @brief This is the configuration file for the scheduler
 * @version 0.1
 * @date 2020-04-7
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "STD_TYPES.h"

#include "SCHED.h"
#include "SCHED_CFG.h"

extern Task t1;

/**
 * @brief This array holds all tasks to be considered by the scheduler
 *
 */
const SysTask_Info sysTasks_cfg[SCHED_MAX_TASK_NUM] = {
                                                   {.appTask = &t1,.firstDelayTicks = 0},
                                                  };
