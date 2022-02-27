#define MAXLINE 1000
#include<stdio.h>
int main()
{
    int getline(char s[],int lim);
    int index(char s[],char t[]);
    char line[MAXLINE];
    while(getline(line,MAXLINE)>0)
        if(index(line,"the")>=0)
            printf("%s\n",line);
}
int getline(char s[],int lim)
{
    int i,c;
    i=0;
    while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]=c;
    s[i]='\0';
    return(i);
}
int index(char s[],char t[])
{
    int i,j,k;
    for(i=0;s[i]!='\0';i++)
    {
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++);
        if(t[k]=='\0')
            return(i);
    }
    return(-1);
}