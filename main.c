#include "STD_TYPES.h"
#include "SCHED.h"

int main(void)
{
    /* 
     * Any necessary initialization must be done here 
     * before calling SCHED_start(), as this function will enter an infinite loop!
     */
    SCHED_init();
    SCHED_start();
}