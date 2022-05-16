#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std; //
#define N 3          //鍋滆溅鍦簆ark
#define M 4          //閫氶亾line

//杞﹀瓙
typedef struct Car
{
    int num;
    int time;
} Car;

//鏍�
typedef struct stack
{
    Car *base;
    Car *top;
    int curlen;
} Park, Tmp;

Park park; //鍋滆溅鍦�(鏍�)
Tmp tmp;   //涓存椂璁╄矾閬�(鏍�)

//閾鹃槦鍒楃粨鐐�:鏁版嵁鍩熶负杞﹀瓙
typedef struct Qnode
{
    Car car;
    struct Qnode *next;
} Qnode, *queuePtr;

//閾鹃槦鍒�
typedef struct queue
{
    queuePtr front;
    queuePtr rear;
    int curlen;
} Line;

Line line; //閫氶亾(閾鹃槦鍒�)

//鍒濆鍖栧仠杞﹀満park(鏍�)
void Initpark()
{
    park.base = new Car[N];
    park.top = park.base;
    park.curlen = 0;
}

//鍒濆鍖栦复鏃惰璺亾tmp(鏍�)
void Inittmp()
{
    tmp.base = new Car[N];
    tmp.top = tmp.base;
    tmp.curlen = 0;
}

//鍒濆鍖栭€氶亾line(閾鹃槦鍒�)
void Initline()
{
    line.front = line.rear = new Qnode;
    line.front->next = NULL;
    line.curlen = 0;
}

//杞﹀瓙杩涘仠杞﹀満park(鏍�)
void Inpark(Car e)
{
    *(park.top) = e;
    park.top++;
    park.curlen++;
    cout << "杞﹁締" << e.num << "鍋滄斁鍦ㄥ仠杞﹀満绗�" << park.curlen << "涓綅缃�." << endl;
}

//杞﹀瓙杩涢€氶亾line(閾鹃槦鍒�)
void Inline(Car e)
{
    Qnode *s = new Qnode;
    s->car = e;
    s->next = NULL;
    line.rear->next = s;
    line.rear = s;
    line.curlen++;
    cout << "杞﹁締" << e.num << "鍋滄斁鍦ㄩ€氶亾绗�" << line.curlen << "涓綅缃�." << endl;
}

//杞﹀瓙杩涘幓涓存椂璁╄矾閬搕mp(鏍�)
void Intmp(Car e)
{
    *(tmp.top) = e;
    tmp.top++;
    tmp.curlen++;
}

//鍑烘爤鎿嶄綔
void Outstack(stack *s)
{
    s->top--;
    s->curlen--;
}

//閫氶亾line(閾鹃槦鍒�)鐨勭涓€杈嗚溅鍗抽槦澶村厓绱�
Car Outline()
{
    Qnode *firstqnode = line.front->next;
    Car firstcar = firstqnode->car;
    line.front->next = firstqnode->next;
    line.curlen--;
    return firstcar;
}

//杞﹀瓙鍑哄仠杞﹀満park
void Outpark(Car e)
{
    int num = e.num;
    int outtime = e.time;  //绂诲紑鏃堕棿
    Car *c = park.top - 1; //鏍堥《鍏冪礌
    while (c->num != num && park.top > park.base)
    {
        Intmp(*c);       //鏍堥《鍏冪礌(杞﹀瓙)杩涗复鏃惰璺亾
        Outstack(&park); //鏍堥《鍏冪礌(杞﹀瓙)鏆傛椂寮瑰嚭鍘�
        c--;
    }
    if (park.top == park.base)
    {
        cout << "鍋滆溅鍦烘棤姝よ溅." << endl;
    }
    else
    {
        int spendtime = outtime - (c->time);
        cout << "鍋滅暀鏃堕棿锛�" << spendtime << endl;
        cout << "鏀惰垂锛�" << spendtime * 2 << endl;
        Outstack(&park); //杞﹀瓙鍑哄仠杞﹀満
    }

    //灏嗘墍鏈変复鏃惰璺亾閲岀殑杞﹀瓙鍑簍mp鏍�,骞跺叆park鏍�
    while (tmp.curlen > 0)
    {
        Outstack(&tmp);
        Inpark(*(tmp.top));
    }

    //璁╅€氶亾line閲岀殑闃熷ご鍏冪礌(杞﹀瓙)杩涘仠杞﹀満park
    while (park.curlen < N && line.curlen > 0)
    {
        Car linefirstcar = Outline();
        linefirstcar.time = e.time;
        Inpark(linefirstcar);
    }
}

void Dispark()
{
    cout << "鍋滆溅鍦�:" << endl;
    Car *p = park.base;
    while (p != park.top)
    {
        cout << "杞﹁締" << p->num << "鍒拌揪鏃堕棿锛�" << p->time << endl;
        p++;
    }
}
void Disline()
{
    cout << "閫氶亾:" << endl;
    Qnode *p = line.front->next;
    while (p)
    {
        cout << "杞﹁締" << (p->car).num << "鍒拌揪鏃堕棿锛�" << (p->car).time << endl;
        p = p->next;
    }
}

int main()
{
    Initpark();
    Inittmp();
    Initline();
    char a[5];
    cout << "璇疯緭鍏ユ搷浣滐細 杞︾墝鍙凤細 鏃堕棿锛�" << endl;
    while (cin >> a)
    {
        if (!strcmp(a, "A"))
        {
            Car car;
            cin >> car.num >> car.time;
            if (park.curlen < N)
                Inpark(car);
            else if (line.curlen < M)
                Inline(car);
            else
                cout << "涓嶅ソ鎰忔€�,鏃犵┖鍦�!" << endl;
        }
        else if (!strcmp(a, "D"))
        {
            Car car;
            cin >> car.num >> car.time;
            Outpark(car);
        }
        else if (!strcmp(a, "P"))
        {
            Dispark();
        }
        else if (!strcmp(a, "W"))
        {
            Disline();
        }
        else if (!strcmp(a, "E"))
        {
            break;
        }
    }
}