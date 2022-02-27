#include<stdio.h>
void calculate(int a,int b)
{
    int i,sum=0;
    for(i=a;i<=b;i++)
    {
        if(i%7==0)
            sum+=i;
    }
    printf("[m,n]之间能被7整除的数字和为%d\n",sum);
}
int main()
{
    int m,n;
    wow:
    printf("请输入整数m和n：\n");
    scanf("%d%d",&m,&n);
    if(m>=n)
    {
        printf("输入的数据不合法，请重新输入！\n");
        goto wow;
    }
    else
        calculate(m,n);
    return 0;
}