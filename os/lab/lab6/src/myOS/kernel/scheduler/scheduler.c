#include "../../include/scheduler.h"
#include "../../include/schedulerFCFS.h"
#include "../../include/schedulerPRIO.h"
#include "../../include/schedulerRR.h"
#include "../../include/schedulerSJF.h"

void init_sch(void)
{
    switch (sch.type)
    {
    case FCFS:
        sch.schedulerInit_func = schedulerInitFCFS;
        sch.nextTsk_func = nextTskFCFS;
        sch.enqueueTsk_func = enqueueTskFCFS;
        sch.dequeueTsk_func = dequeueTskFCFS;
        sch.schedule = scheduleFCFS;
        sch.tick_hook = NULL;
        break;
    case PRIO:
        sch.schedulerInit_func = schedulerInitPRIO;
        sch.nextTsk_func = nextTskPRIO;
        sch.enqueueTsk_func = enqueueTskPRIO;
        sch.dequeueTsk_func = dequeueTskPRIO;
        sch.schedule = schedulePRIO;
        sch.tick_hook = NULL;
        break;
    case RR:
        sch.schedulerInit_func = schedulerInitRR;
        sch.nextTsk_func = nextTskRR;
        sch.enqueueTsk_func = enqueueTskRR;
        sch.dequeueTsk_func = dequeueTskRR;
        sch.schedule = scheduleRR;
        sch.tick_hook = NULL;
        break;
    case SJF:
        sch.schedulerInit_func = schedulerInitSJF;
        sch.nextTsk_func = nextTskSJF;
        sch.enqueueTsk_func = enqueueTskSJF;
        sch.dequeueTsk_func = dequeueTskSJF;
        sch.schedule = scheduleSJF;
        sch.tick_hook = NULL;
        break;
    }
}