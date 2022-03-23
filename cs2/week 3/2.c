#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int YEAR[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
struct true_year
{
    int hour, min, sec, day, month, year;
};
bool judge(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    else
        return false;
}
void change(struct true_year p)
{
    int mhour, mmin, msec, mday, mmonth, myear;
    mhour = mmin = msec = mday = mmonth = myear = 0;
    for (int i = 2000; i < p.year; i++)
    {
        if (judge(i) == true)
            mday += 366;
        else
            mday += 365;
    }
    int temp = judge(p.year) ? 1 : 0;
    for (int i = 0; i < p.month - 1; i++)
        mday += YEAR[temp][i];
    mday += p.day - 1;
    myear = mday / 1000;
    mday %= 1000;
    mmonth = mday / 100 + 1;
    mday = mday % 100 + 1;
    msec = (p.hour * 60 * 60 + p.min * 60 + p.sec) * pow(10, 1 + 2 + 2) / (24 * 60 * 60);
    mhour = msec / pow(10, 4);
    msec %= 10000;
    mmin = msec / 100;
    msec %= 100;
    printf("%d:%d:%d %d.%d.%d\n", mhour, mmin, msec, mday, mmonth, myear);
}
int main()
{
    int N;
    scanf("%d", &N);
    struct true_year s[N];
    for (int i = 0; i < N; i++)
        scanf("%d:%d:%d %d.%d.%d", &s[i].hour, &s[i].min, &s[i].sec, &s[i].day, &s[i].month, &s[i].year);
    for (int i = 0; i < N; i++)
        change(s[i]);
    return 0;
}