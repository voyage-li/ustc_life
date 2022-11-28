#include <stdio.h>
#define N 1000000

int main()
{
    int i, j, k, n;
    int a[n];
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int sum[n];
    for (j = 0; j < n - 2; j++)
    {
        sum[j] = a[j] + a[j + 1] + a[j + 2];
    }

    int min = sum[0];
    for (k = 0; k < n - 2; k++)
    {
        if (sum[k] <= min)
        {
            min = sum[k];
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%d", k);
    }
    return 0;
}
