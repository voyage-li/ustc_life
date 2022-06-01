#include "FCFSTestCase.h"

void myTskFCFS0(void)
{
    task_execute(4);
}

void myTskFCFS1(void)
{
    task_execute(5);
}

void myTskFCFS2(void)
{
    task_execute(3);
}

void myTskFCFS4(void)
{
    task_execute(2);
}

void FCFS_TEST(void)
{
    // correct execute order:
    // init -> 4 -> 2 -> 1 -> idle -> 3 -> idle (the numbers are tid)

    int newTskTid0 = createTsk(myTskFCFS0); // its tid will be 1
    setTskPara(ARRTIME, 3, TCB[newTskTid0]->para);
    setTskPara(EXETIME, 4, TCB[newTskTid0]->para);

    int newTskTid1 = createTsk(myTskFCFS1); // its tid will be 2
    setTskPara(ARRTIME, 1, TCB[newTskTid1]->para);
    setTskPara(EXETIME, 5, TCB[newTskTid1]->para);

    int newTskTid2 = createTsk(myTskFCFS2); // its tid will be 3
    setTskPara(ARRTIME, 13, TCB[newTskTid2]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid2]->para);

    int newTskTid4 = createTsk(myTskFCFS4); // its tid will be 4
    setTskPara(ARRTIME, 0, TCB[newTskTid4]->para);
    setTskPara(EXETIME, 2, TCB[newTskTid4]->para);

    add_task(newTskTid0);
    add_task(newTskTid4);
    add_task(newTskTid1);
    add_task(newTskTid2);
}
