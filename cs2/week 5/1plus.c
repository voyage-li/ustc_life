#include <stdio.h>
int main()
{
    int n, index, j = 0, now = 1;
    int a[32] = {0};
    a[0] = 1;
    scanf("%d", &n);

    for (index = 0; index < n; index++)
    {
        int flag = 0, count = 0; //use flag to judge carry,use count to record the length of array
        for (j = 0; j <= now; j++)
        {
            a[j] = a[j] * 2 + flag;
            flag = 0;
            if (a[j] >= 10)
            {
                flag = a[j] / 10;
                a[j] = a[j] % 10;
            }
        }
        if (a[now] && a[now + 1] == 0)
            count = 1;
        else
            count = 0;
        now += count; //whether now should be +1
    }
    for (index = now - 1; index >= 0; index--)
        printf("%d", a[index]);

    return 0;
}