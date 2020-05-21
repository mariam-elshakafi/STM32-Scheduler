/**
 * @file SCHED.h
 * @author Mariam El-Shakafi (mariam.elshakafi@gmail.com)
 * @brief This is the user interface file for the scheduler
 * @version 0.1
 * @date 2020-04-7
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef SCHED_H
#define SCHED_H

typedef void (*taskRunnable)(void);


/**
 * @brief Task typedef that's used by ther modules to define a task
 * 
 */
typedef struct
{
  taskRunnable runnable;
  u32 periodicTimeMS;
  u32 priority;
} Task;


/**
 * @brief This API is used to initialize scheduler
 * 
 */
void SCHED_init(void);

/**
 * @brief This API starts scheduling.
 * @note This must be called last after all initializations are finished, as system will enter an infinite loop.
 * 
 */
void SCHED_start(void);

#endif
