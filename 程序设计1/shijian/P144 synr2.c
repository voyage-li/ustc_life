#include<stdio.h>
int m,n,zuida,zuixiao;
void max(int a,int b)
{
    int temp,judge;
    if(a<b)
    {
        temp=a;
        a=b;
        b=temp;
    }
    int i;
    for(i=0;;i++)
    {
        judge=a-b;
        if(judge==b)
            break;
        a=judge;
        if(a<b)
        {
            temp=a;
            a=b;
            b=temp;
        }
    }
    zuida=temp;
}
void min(int a,int b,int c)
{
    int temp;
    temp=(b*c)/a;
    zuixiao=temp;
}
int main()
{
    printf("请输入两个整数：\n");
    scanf("%d%d",&m,&n);
    max(m,n);
    min(zuida,m,n);
    printf("最大公约数：%d\n最小公倍数：%d\n",zuida,zuixiao);
    return 0;
}