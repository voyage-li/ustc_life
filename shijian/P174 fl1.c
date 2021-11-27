#include"stdio.h"
#define N 5
struct student
{
    char sex,name[16];
    int birthday;
};
int main()
{
    struct student class[N];
    void input(struct student *p,int n);
    void count(struct student s[],int n,int *cl994,int *cm,int *cf);
    int count1994=0,countm=0,countf=0;
    input(class,N);
    count(class,N,&count1994,&countm,&countf);
    printf("male:%d\n",countm);
    printf("female:%d\n",countf);
    printf("birthdad=1994:%d\n",count1994);
}
void input(struct student *p,int n)
{
    struct student *pend;
    pend=p+n-1;
    printf("NAME,SEX[m/f],BIRTHDAYN\n");
    for(;p<=pend;p++)
    {
        scanf("%s %c%d",p->name,&p->sex,&p->birthday);
        getchar();
    }
}
void count(struct student s[],int n,int *c1994,int *cm,int *cf)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].birthday==1994)
            ++*c1994;
        if(s[i].sex=='m')
            ++*cm;
        else
            ++*cf;
    }
}