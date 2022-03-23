#include<stdio.h>
int main()
{
	char a,b,c;
	a=getchar();
	b=getchar();
	c=getchar();
	printf("%c%c%c\n",a,b,c);
	printf("%c%c%c\n",c,b,a);
	return 0;
}
