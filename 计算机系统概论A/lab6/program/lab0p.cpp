#include <iostream>
short times(short a, short b)
{
    if (b == 0)
        return 0;
    int flag = 0;
    if (b < 0)
    {
        flag = 1;
        b = -b;
    }
    short answer = 0;
    while (b)
    {
        if (b & 1)
            answer += a;
        a = a << 1;
        b = b >> 1;
    }
    if (flag == 1)
        answer = -answer;
    return answer;
}