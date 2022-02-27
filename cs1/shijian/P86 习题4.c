#include<stdio.h>
int main()
{
	double F,x;
	printf("请输入自变量的值:\n");
	scanf("%lf",&x);
	if(x<0&&x!=-3)
		F=x*x+x-6;
	else if(x>=0&&x<10&&x!=2&&x!=3)
		F=x*x-5*x+6;
	else
		F=x*x-x-1;
	printf("x=%lf\nf(x)=%lf",x,F);
	return 0;
}
