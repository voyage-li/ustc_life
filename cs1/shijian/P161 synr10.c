#include<stdio.h>
float maxfun(float *a,int x)
{
    float temp=*a;
    int i;
    for(i=0;i<x;i++)
        if(temp<*(a+i))
            temp=*(a+i);
    return temp;
}
float minfun(float *a,int x)
{
    float temp=*a;
    int i;
    for(i=0;i<x;i++)
        if(temp>*(a+i))
            temp=*(a+i);
    return temp;
}
int main()
{
    printf("请输入你想要输入的元素个数：\n");
    int x,i;
    scanf("%d",&x);
    float a[x];
    printf("请输入数组：\n");
    for(i=0;i<x;i++)
        scanf("%f",&a[i]);
    float *p;
    p=&a[0];
    float max=maxfun(p,x);
    float min=minfun(p,x);
    printf("max=%f,min=%f\n",max,min);
}