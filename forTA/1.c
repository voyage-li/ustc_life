#include <stdio.h>
int main()
{
    int i;
    double GPA;
    for (i = 1; i <= 4; i = i + 1)
    {
        printf("请输入GPA\n");
        scanf("%lf", &GPA);
        if (GPA > 4.3)
            printf("你作弊啦！！！\n");
        else if (GPA == 4.3)
            printf("已经很棒了！\n");
        else if (GPA < 4.3 && GPA >= 0)
            printf("还要继续努力噢\n");
        else
            printf("输入错误");
    }
    return 0;
}