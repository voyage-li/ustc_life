#include<stdio.h>
#include<string.h>
void main()
{
    void sort(char *s[],int n);
    static char *str[5]={"basic","fortran","cobol","pascal","c"};
    int i;
    sort(str,5);
    printf("new sequence of string is:\n");
    for(i=0;i<5;i++)
        printf("%s\n",str[i]);    
}
void sort(char *s[],int n)
{
    char *temp;int i,j,k;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(strcmp(s[k],s[j])>0) k=j;
        if(k!=i)
        {
            temp=s[i];
            s[i]=s[k];
            s[k]=temp;
        }
    }
}