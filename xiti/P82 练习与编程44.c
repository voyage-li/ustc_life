#include<stdio.h>
int main()
{
	char a[500];
	int i;
	while((a[i]=getchar())!=EOF)
	{
		if(a[i]==a[i-1]);	
		else
			putchar(a[i]);
		i++;
	}
} 
