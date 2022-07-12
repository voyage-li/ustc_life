#include "PRIOTestCase.h"

void myTskPrio0(void)
{
    task_execute(4);
}

void myTskPrio1(void)
{
    task_execute(3);
}

void myTskPrio2(void)
{
    task_execute(3);
}

void myTskPrio3(void)
{
    task_execute(3);
}

void myTskPrio4(void)
{
    task_execute(3);
}

void myTskPrio5(void)
{
    task_execute(3);
}

void PRIO_TEST(void)
{

    int newTskTid0 = createTsk(myTskPrio0); // its tid will be 1
    setTskPara(PRIORITY, 3, TCB[newTskTid0]->para);
    setTskPara(ARRTIME, 0, TCB[newTskTid0]->para);
    setTskPara(EXETIME, 4, TCB[newTskTid0]->para);

    int newTskTid1 = createTsk(myTskPrio1); // its tid will be 2
    setTskPara(PRIORITY, 1, TCB[newTskTid1]->para);
    setTskPara(ARRTIME, 1, TCB[newTskTid1]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid1]->para);

    int newTskTid2 = createTsk(myTskPrio2); // its tid will be 3
    setTskPara(PRIORITY, 0, TCB[newTskTid2]->para);
    setTskPara(ARRTIME, 1, TCB[newTskTid2]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid2]->para);

    int newTskTid3 = createTsk(myTskPrio3); // its tid will be 4
    setTskPara(PRIORITY, 4, TCB[newTskTid3]->para);
    setTskPara(ARRTIME, 1, TCB[newTskTid3]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid3]->para);

    int newTskTid4 = createTsk(myTskPrio4); // its tid will be 5
    setTskPara(PRIORITY, 4, TCB[newTskTid4]->para);
    setTskPara(ARRTIME, 4, TCB[newTskTid4]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid4]->para);

    int newTskTid5 = createTsk(myTskPrio5); // its tid will be 6
    setTskPara(PRIORITY, 4, TCB[newTskTid5]->para);
    setTskPara(ARRTIME, 6, TCB[newTskTid5]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid5]->para);

    add_task(newTskTid5);
    add_task(newTskTid1);
    add_task(newTskTid2);
    add_task(newTskTid4);
    add_task(newTskTid3);
    add_task(newTskTid0);
}