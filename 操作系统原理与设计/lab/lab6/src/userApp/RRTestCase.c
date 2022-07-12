#include "RRTestCase.h"

void myTskRR0(void)
{
    task_execute(14);
}

void myTskRR1(void)
{
    task_execute(4);
}

void myTskRR2(void)
{
    task_execute(4);
}

void myTskRR3(void)
{
    task_execute(3);
}

void myTskRR4(void)
{
    task_execute(4);
}

void myTskRR5(void)
{
    task_execute(4);
}

void RR_TEST(void)
{

    int newTskTid0 = createTsk(myTskRR0); // tid 1
    setTskPara(ARRTIME, 0, TCB[newTskTid0]->para);
    setTskPara(EXETIME, 14, TCB[newTskTid0]->para);

    int newTskTid1 = createTsk(myTskRR1); // tid 2
    setTskPara(ARRTIME, 1, TCB[newTskTid1]->para);
    setTskPara(EXETIME, 4, TCB[newTskTid1]->para);

    int newTskTid2 = createTsk(myTskRR2); // tid 3
    setTskPara(ARRTIME, 2, TCB[newTskTid2]->para);
    setTskPara(EXETIME, 4, TCB[newTskTid2]->para);

    int newTskTid3 = createTsk(myTskRR3); // tid 4
    setTskPara(ARRTIME, 15, TCB[newTskTid3]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid3]->para);

    int newTskTid4 = createTsk(myTskRR4); // tid 5
    setTskPara(ARRTIME, 15, TCB[newTskTid4]->para);
    setTskPara(EXETIME, 4, TCB[newTskTid4]->para);

    int newTskTid5 = createTsk(myTskRR5); // tid 6
    setTskPara(ARRTIME, 26, TCB[newTskTid5]->para);
    setTskPara(EXETIME, 4, TCB[newTskTid5]->para);

    add_task(newTskTid1);
    add_task(newTskTid0);
    add_task(newTskTid5);
    add_task(newTskTid4);
    add_task(newTskTid3);
    add_task(newTskTid2);
}
