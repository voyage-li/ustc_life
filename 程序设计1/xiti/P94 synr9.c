#include<stdio.h>
char *s,*p,*q;
int i,j;
char Arrange[62];
char a[100],b[100];
void luru()
{
    printf("请输入两个字符串\n");
    for(i=0;(*(s+i)=getchar())!='\n';i++);
    for(i=0;(*(p+i)=getchar())!='\n';i++);
}
void shengcheng()
{
    int i;
    for(i=0;i<=50;i+=2)
        Arrange[i]='A'+i/2;
    for(i=1;i<=51;i+=2)
        Arrange[i]='a'+i/2;
    for(i=52;i<62;i++)
        Arrange[i]=48+i-52;
    q=&Arrange[0];
}
void panduan()
{
    int m,n;
    for(int d=0;d<200;d++)
    {
        m=n=-1;
        for(i=d;*(s+i)!='\n';i++)
        {
            for(j=0;j<62;j++)
                if(*(s+i)==*(q+j))
                {
                    m=j;
                    break;
                }
            if(m!=-1)
                break;
        }
        for(i=d;*(p+i)!='\n';i++)
        {
            for(j=0;j<62;j++)
                if(*(p+i)==*(q+j))
                {
                    n=j;
                    break;
                }
            if(n!=-1)
                break;
        }
        if(m<n)
            break;
        else if(m>n)
        {
            s=&b[0];
            p=&a[0];
            break;
        }
    }
}
int main()
{
    s=&a[0];
    p=&b[0];
    luru();
    shengcheng();
    panduan();
    printf("\n");
    for(i=0;*(s+i)!='\n';i++)
        printf("%c",*(s+i));
    printf("\n");
    for(i=0;*(p+i)!='\n';i++)
        printf("%c",*(p+i));
}