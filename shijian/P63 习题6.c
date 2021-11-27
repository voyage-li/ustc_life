#include<stdio.h>
#include<math.h>
main()
{
	float a,b,c,p,d,x1,x2;
	a=1.0;
	b=-(1.0e+12+1.0);
	c=1.0e+12;
	p=sqrt(b*b-4*a*c);
	d=2.0*a;
	x1=(-b+p)/d;
	x2=(-b-p)/d;
	printf("x1=%e\nx2=%e\n",x1,x2);
}
