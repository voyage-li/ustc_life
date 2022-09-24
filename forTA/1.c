#include <stdio.h>
int main()
{
    short i;
    unsigned short j;
    i = j = -50;
    i = i / 2;
    j = j / 2;
    printf("%d %d\n", i, j);
    return 0;
}