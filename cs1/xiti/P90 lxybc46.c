#include<stdio.h>
#include<math.h>
int judge,i,j,temp,jilu=0;
void define(int a)
{
    judge=0;
    for(j=2;j<=sqrt(a);j+=1)
        if(a%j==0)
        {
            judge++;
            break;
        }
}
int exchange(int a)
{
    int sum=0,count=1;
    for(j=1;a>=pow(10,j);j++)
        count++;
    int Array[count+1];
    for(i=count;i>=1;i--)
    {
        Array[i]=a/pow(10,i-1);
        a=a-Array[i]*pow(10,i-1);
    }
    for(i=1;i<=count;i++)
        sum+=Array[i]*pow(10,count-i);
    return sum;
}
int main()
{
    int m,n,fan;
    wow:
    printf("请输入整数m和n：\n");
    scanf("%d%d",&m,&n);
    printf("\n");
    if(m>=n)
    {
        printf("输入的数据不合法，请重新输入！\n");
        goto wow;
    }
    else
    {
        for(i=m;i<n+1;i++)
        {
            temp=i;
            define(temp);
            if(judge==0)
            {   
                fan=exchange(i);
                define(fan);
            }
            if(judge==0)
            {    
                if(temp!=1)
                    printf("%d\n",temp);
                jilu++;            
            }
            i=temp;
        }
    }
    if(jilu==0)
        printf("0");
    return 0;
}