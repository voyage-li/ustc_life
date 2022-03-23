#include<stdio.h>
int main()
{
	int a,b;
	char c1,c2;
	float d,e;
	double f,g;
	long m,n;
	unsigned int p,q;
	scanf("%d%d%c%c%f%f",&a,&b,&c1,&c2,&d,&e);
	scanf("%lf,%lf,%ld,%ld,%u,%u",&f,&g,&m,&n,&p,&q);
	printf("sizeof:%d,a=%d,b=%d\n",sizeof(int),a,b);
	printf("sizeof:%d,c1=%c,c2=%c\n",sizeof(char),c1,c2);
	printf("sizeof:%d,d=%-6.2f,e=%-6.2f\n",sizeof(float),d,e);
	printf("sizeof:%d,f=%-15.6f,g=%-15.12f\n",sizeof(double),f,g);
	printf("sizeof:%d,m=%ld,n=%ld\n",sizeof(long),m,n);
	printf("sizeof:%d,p=%u,q=%u\n",sizeof(unsigned),p,q);
 } 
