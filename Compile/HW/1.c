#include <stdio.h>
int main()
{
    int leap_year[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int common_year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int N, day, M;
    int i, j, t;
    scanf("%d,%d", &N, &M);
    if ((N % 4 == 0 && M % 100 != 0) || (M % 400 == 0))
    {
        for (i = 0; i < 12; i++)
        {
            printf("%d年%d月\n", N, i + 1);
            printf("星期一星期二星期三星期四星期五星期六星期日\n");
            t = M % 7;
            if (t != 0)
            {
                for (j = 1; j < t; j++)
                {
                    printf("      ");
                }
            }
            else
                for (i = 0; i < 6; i++)
                {
                    printf("      ");
                }
            for (j = 1; j < t; j++)
            {
                printf("      ");
            }
            for (day = 1; day <= leap_year[i]; day++)
            {
                printf("  %2d  ", day);
                M += 1;
                if ((day != leap_year[i]) && (M - 1) % 7 == 0)
                    printf("\n");
            }
            printf("\n");
        }
    }
    else
        for (i = 0; i < 12; i++)
        {
            printf("%d年%d月\n", N, i + 1);
            printf("星期一星期二星期三星期四星期五星期六星期日\n");
            t = M % 7;
            if (t != 0)
            {
                for (j = 1; j < t; j++)
                {
                    printf("      ");
                }
            }
            else
                for (i = 0; i < 6; i++)
                {
                    printf("      ");
                }
            for (j = 1; j < t; j++)
            {
                printf("      ");
            }
            for (day = 1; day <= common_year[i]; day++)
            {
                printf("  %2d  ", day);
                M += 1;
                if ((day != common_year[i]) && (M - 1) % 7 == 0)
                    printf("\n");
            }
            printf("\n");
        }
    return 0;
}