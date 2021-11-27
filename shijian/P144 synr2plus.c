#include<stdio.h>
int max(int a,int b)
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
    return temp;
}
int min(int a,int b,int c)
{
    int temp;
    temp=(b*c)/a;
    return temp;
}
int main()
{
    int m,n,zuida,zuixiao;
    printf("请输入两个整数：\n");
    scanf("%d%d",&m,&n);
    zuida=max(m,n);
    zuixiao=min(zuida,m,n);
    printf("最大公约数：%d\n最小公倍数：%d\n",zuida,zuixiao);
    return 0;
}