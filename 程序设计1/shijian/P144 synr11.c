#include<stdio.h>
#define swap(a,b) a=a+b;b=a-b;a=a-b;
int main()
{
    int m,n;
    printf("请输入两个数:\n");
    scanf("%d%d",&m,&n);
    swap(n,m)
    printf("%d %d",m,n);
    return 0;
}