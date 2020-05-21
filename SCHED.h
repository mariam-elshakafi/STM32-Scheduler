typedef void (*taskRunnable)(void);

typedef struct
{
  taskRunnable runnable;
  u32 periodicTimeMS;
  u32 priority;
} Task;


void SCHED_init(void);
void SCHED_start(void);
