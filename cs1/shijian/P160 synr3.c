#include<stdio.h>
int n,*p;
void arrange(int *p)
{
    for(int i=0;i<n;i++)
    {
        int m=i;
        for(int j=i;j<n;j++)
        {
            if(*(p+i)<*(p+j)&&*(p+m)<*(p+j))
                m=j;
        }
        if(m!=i)
        {
            int temp;
            temp=*(p+m);
            *(p+m)=*(p+i);
            *(p+i)=temp;
        }
    }
}
int main()
{
    printf("请输入你想要输入的整数个数：\n");
    scanf("%d",&n);
    printf("请输入%d个整数：\n",n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    p=&a[0];
    arrange(p);
    for(int i=0;i<n;i++)
        printf("%d ",*(p+i));
}