#include<stdio.h>
char a[100];
int k;
void reverse(char c[])
{
    int i,j;
    char count[100];
    for(i=0;c[i]!='\n';i++);
    for(j=0;j<i;j++)
        count[j]=c[i-1-j];
    for(j=0;j<i;j++)
        a[j]=count[j];
}
int main()
{
    for(k=0;;k++)
    {
        a[k]=getchar();
        if(a[k]=='\n')
            break;
    }
    reverse(a);
    for(k=0;a[k]!='\n';k++)
        printf("%c",a[k]);
}