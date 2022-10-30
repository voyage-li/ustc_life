#include <stdio.h>
int main()
{
    int tmp, n;
    int a[1000];
    int value[1000] = {0};
    int times[1000] = {0};
    int num = 0;
    while (1)
    {
        printf("有几个正整数？");
        scanf("%d", &n);
        if (n > 1 && n < 1000)
            break;
        else
            printf("输入项数不合理，请重新输入！\n");
    }
    printf("请输入%d个正整数：", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        times[a[i]]++;
    for (int i = 0; i < 1000; i++)
        if (times[i] != 0)
            printf("%d出现%d次\n", i, times[i]);

    return 0;
}
