#include<stdio.h>
#define MAXLINE 100
void main()
{
	int getline(char s[],int lim);
	void copy(char s1[],char s2[]);
	void sort(char s[],int l);
	int len,max=0;char line[MAXLINE],save[MAXLINE];
	while((len=getline(line,MAXLINE))>0)
		if(len>max)
		{
			max=len;copy(line,save);
		}	
	if(max>0)
		printf("%d %s\n",max,save);
	sort(save,max);
	printf("%d %s\n",max,save);
} 

getline(char s[],int lim)
{
	int c,i;
	for(i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n';i++)
		s[i]=c;
	if(c=='\n')
		s[i++]=c;
	s[i]='\0';
	return(i);
}

void copy(char s1[],char s2[])
{
	int i=0;
	while((s2[i]=s1[i])!='\0')
		++i;
}

void sort(char s[],int l)
{
	int i,j,k;
	char t;
	for(i=0;i<l-1;i++)
	{
		k=i;
		for(j=i+1;j<l;j++)
			if(s[j]<s[k])k=j;
		t=s[k];s[k]=s[i];s[i]=t;
	}
}
