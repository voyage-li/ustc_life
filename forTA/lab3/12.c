#include <stdio.h>
#include <time.h>
int main()
{
    FILE *fpi, *fpo;
    time_t seconds;
    char days_mons[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}, leap = 0;
    int year, month, day, hour, minute, second;
    float a[100], temp;
    int n;
    int i, j, k, t;

    printf("有几个数（1~100）：");
    scanf("%d", &n);
    fpi = fopen("data.txt", "r");
    //第一次运行程序
    if (fpi == NULL)
    {
        fpi = fopen("data.txt", "w+");
        printf("输入%d个数：", n);
        for (i = 0; i < n; i++)
        {
            scanf("%f", &a[i]);
            fprintf(fpi, "%.6f ", a[i]);
        }
        rewind(fpi);
    }

    fpo = fopen("result.txt", "a");
    printf("有几个数（1~100）：");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        fscanf(fpi, "%f", &a[i]);
    fclose(fpi);
    //时间戳
    seconds = time(NULL) + 8 * 60 * 60;
    second = seconds % 60;
    seconds /= 60;
    minute = seconds % 60;
    seconds /= 60;
    hour = seconds % 24;
    seconds /= 24;
    year = 1970;
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ? 1 : 0;
    while (seconds > 365)
    {
        if (leap)
            seconds -= 366;
        else
            seconds -= 365;
        year++;
        leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ? 1 : 0;
    }
    month = 1;
    for (i = 0; seconds >= days_mons[leap][i]; i++, month++)
        seconds -= days_mons[leap][i];
    day = seconds + 1;
    // insert_sort
    for (i = 0; i < n - 1; i++) //排好序的元素的max下标
        for (j = 0; j <= i; j++)
            if (a[j] > a[i + 1])
            {
                temp = a[i + 1];
                for (k = i + 1; k > j; k--)
                    a[k] = a[k - 1];
                a[j] = temp;
                break;
            }

    fprintf(fpo, "%d-%02d-%02d,%02d:%02d:%02d\n", year, month, day, hour, minute, second);
    for (i = 0; i < n; i++)
        fprintf(fpo, "%.6f ", a[i]);
    fprintf(fpo, "\n");
    fclose(fpo);
    return 0;
}
