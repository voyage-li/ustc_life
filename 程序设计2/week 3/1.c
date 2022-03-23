#include <stdio.h>
#include <math.h>
int change(int a)
{
    int result = 0;
    int i = 0;
    while (a != 0)
    {
        result += pow(10, i++) * (a % 8);
        a = a / 8;
    }
    return result;
}
int main()
{
    int num[100];
    int i = 0;
    while ((scanf("%d", &num[i++])) > 0)
        ;
    num[i - 1] = 0;
    i = 0;
    while (num[i] != 0)
        printf("%d\n", change(num[i++]));
    return 0;
}