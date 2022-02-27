#include<stdio.h>
#define N 12
void main()
{
    static float a[]={1.5,3.8,5.6,7.8,91.6,1.61,13.3,15.0,17.5,19.9,21.7,23.0};
    float arr_add(float arr[],int n);
    float odd_add(float *p,int n);
    float arr_ave(float *p,int n);
    float arr_max(float a[],int n);
    void process(float *p,float(*fun)(),int n);
    int n=N;
    printf("the sum of %d elements is:",n);
    process(a,arr_add,n);
    printf("the sum of odd elements is:");
    process(a,odd_add,n);
    printf("the average of %d elements is:",n);
    process(a,arr_ave,n);
    printf("the maxinum of %d elements is:",n);
    process(a,arr_max,n);
    return;
}
float arr_add(float arr[],int n)
{
    int i;
    float sum=0;
    for(i=0;i<n;i++)
        sum=sum+arr[i];
    return(sum);
}
float odd_add(float *p,int n)
{
    int i;
    float sum=0;
    for(i=0;i<n;i=i+2,p=p+2)
        sum=sum+*p;
    return(sum);
}
float arr_ave(float *p,int n)
{
    int i;
    float sum=0,ave;
    for(i=0;i<n;i++)
        sum=sum+p[i];
    ave=sum/n;
    return(ave);
}
float arr_max(float a[],int n)
{
    int i=0;
    float temp=a[i++];
    for(;i<n;i++)
        if(temp<a[i])
            temp=a[i];
    return(temp);
}
void process(float *p,float(*fun)(),int n)
{
    float result;
    result=(*fun)(p,n);
    printf("%8.2f\n",result);
}
