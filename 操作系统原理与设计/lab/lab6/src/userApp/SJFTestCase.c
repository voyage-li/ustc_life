#include "SJFTestCase.h"

void myTskSJF0(void)
{
    task_execute(2);
}

void myTskSJF1(void)
{
    task_execute(5);
}

void myTskSJF2(void)
{
    task_execute(4);
}

void myTskSJF3(void)
{
    task_execute(3);
}

void myTskSJF4(void)
{
    task_execute(3);
}

void myTskSJF5(void)
{
    task_execute(3);
}

void myTskSJF6(void)
{
    task_execute(10);
}

void SJF_TEST(void)
{
    // correct execute order:
    // init -> 1 -> 3 -> 2 -> 4 -> 6 -> 5 -> 7 -> idle (the numbers are tid)

    int newTskTid0 = createTsk(myTskSJF0); // its tid will be 1
    setTskPara(ARRTIME, 0, TCB[newTskTid0]->para);
    setTskPara(EXETIME, 2, TCB[newTskTid0]->para);

    int newTskTid1 = createTsk(myTskSJF1); // its tid will be 2
    setTskPara(ARRTIME, 0, TCB[newTskTid1]->para);
    setTskPara(EXETIME, 5, TCB[newTskTid1]->para);

    int newTskTid2 = createTsk(myTskSJF2); // its tid will be 3
    setTskPara(ARRTIME, 0, TCB[newTskTid2]->para);
    setTskPara(EXETIME, 4, TCB[newTskTid2]->para);

    int newTskTid3 = createTsk(myTskSJF3); // its tid will be 4
    setTskPara(ARRTIME, 10, TCB[newTskTid3]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid3]->para);

    int newTskTid4 = createTsk(myTskSJF4); // its tid will be 5
    setTskPara(ARRTIME, 12, TCB[newTskTid4]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid4]->para);

    int newTskTid5 = createTsk(myTskSJF5); // its tid will be 6
    setTskPara(ARRTIME, 11, TCB[newTskTid5]->para);
    setTskPara(EXETIME, 3, TCB[newTskTid5]->para);

    int newTskTid6 = createTsk(myTskSJF6); // its tid will be 7
    setTskPara(ARRTIME, 0, TCB[newTskTid6]->para);
    setTskPara(EXETIME, 10, TCB[newTskTid6]->para);

    add_task(newTskTid5);
    add_task(newTskTid1);
    add_task(newTskTid2);
    add_task(newTskTid4);
    add_task(newTskTid3);
    add_task(newTskTid0);
    add_task(newTskTid6);
}
