#include <stdio.h>
int main()
{
    char a[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    char *p = *a, (*q)[4] = a;
}