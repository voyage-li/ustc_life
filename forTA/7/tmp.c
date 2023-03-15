#include <stdio.h>
#include <string.h>
int main()
{
    int m, n;
    int tmp1, tmp2;
    int a[1000][2];
    int b[1000][2];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 999; i >= 0; i--)
    {
        a[i][1] = i;
        b[i][1] = i;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        a[tmp2][0] = tmp1;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        b[tmp2][0] = tmp1;
    }
    int ans[2000][2];
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < 2000; i++)
    {
        ans[i][1] = i;
        for (int j = 0; j <= i; j++)
        {
            if (!(j < 1000 && i - j < 1000))
                continue;
            if (a[j][0] * b[i - j][0] != 0)
                ans[i][0] += a[j][0] * b[i - j][0];
        }
    }
    for (int i = 2000 - 1; i >= 0; i--)
    {
        if (ans[i][0] != 0)
            printf("%d %d ", ans[i][0], ans[i][1]);
    }
    return 0;
}