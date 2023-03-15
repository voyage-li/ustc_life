#include <stdio.h>
#include <stdlib.h>
int max = 0;
int loc = 0;
int main()
{
    int num;
    int i = 0;
    int data[3];
    scanf("%d", &num);
    while (num--)
    {
        scanf("%d", &data[(i++) % 3]);
        if (i >= 3 && data[0] + data[1] + data[2] > max)
        {
            loc = i - 3;
            max = data[0] + data[1] + data[2];
        }
    }
    printf("%d", loc);
    return 0;
}