#include<stdio.h>
int main()
{
	char a,b,c,d,e,f;
	scanf("%c%c",&a,&b);
	getchar();
	c=getchar();
	d=getchar();
	printf("%c%c%c%c\n",a,b,c,d);
	printf("%c%d\n",a,a);
	scanf("%c%c",&e,&f);
	printf("%6d%6d\n",e,f);
	printf("%8d%8d\n",sizeof(a),sizeof(b));
	putchar(a);
	putchar(c);
	return 0;
 } 
