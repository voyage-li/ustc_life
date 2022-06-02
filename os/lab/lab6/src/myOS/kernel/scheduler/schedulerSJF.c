#include "../../include/schedulerSJF.h"
#include "../../include/myPrintk.h"

myTCB *nextTskSJF(void)
{
    return SJF_pop();
}

void enqueueTskSJF(myTCB *tsk)
{
    SJF_push(tsk);
}

myTCB *dequeueTskSJF(void)
{
    return SJF_pop();
}

void schedulerInitSJF(void)
{
    heap_init_SJF();
}

void print_sjf()
{
    for (int i = 1; i < length_SJF; i++)
        myPrintk(0x6, "sjf_dataid: %d tid:%d exe: %d arr: %d\n", i, SJF_data[i]->tid, SJF_data[i]->para->exeTime, SJF_data[i]->para->arrTime);
}

void scheduleSJF()
{
    while (1)
    {
        myTCB *nextTsk;
        int idleTid;
        if (SJF_empty())
        {
            if (!idleTsk)
                idleTid = createTsk(idleTskBody);

            nextTsk = idleTsk = TCB[idleTid];
        }
        else
            nextTsk = dequeueTskSJF();
        if (nextTsk == idleTsk && currentTsk == idleTsk)
            continue;
        if (currentTsk)
        {
            if (currentTsk == idleTsk)
                destroyTsk(currentTsk->tid);
            if (currentTsk == idleTsk)
                idleTsk = NULL;
        }

        nextTsk->status = RUNNING;
        currentTsk = nextTsk;
        context_switch(&BspContext, currentTsk->stack_top);
        // print_sjf();
    }
}