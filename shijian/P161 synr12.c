#include<stdio.h>
int main()
{
    int *a;
    int *b;
    int n,i;
    printf("请输入向量的维度：\n");
    scanf("%d",&n);
    b=(int*)malloc(n*sizeof(int));
    a=(int*)malloc(n*sizeof(int));
    printf("请输入第一个向量的坐标：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("请输入第二个向量的坐标：");
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    int sum=0;
    for(i=0;i<n;i++)
        sum+=a[i]*b[i];
    printf("向量的乘积为：%d",sum);
}