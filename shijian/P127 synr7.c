#include<stdio.h>
int i,j;
void udf_strat(char a[],char b[])
{
    for(i=0;i<20;i++)
        if(a[i]=='\0')
    for(j=0;j<20;(j++,i++))
    {
            if(b[j]=='\0')
                break;
            a[i]=b[j];
    }
    printf("%s",a);
}
int main()
{
    char s1[40],s2[40];
    scanf("%s",&s1);
    scanf("%s",&s2);
    udf_strat(s1,s2);
    return 0;
}
