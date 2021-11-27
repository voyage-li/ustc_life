#include<stdio.h>
int main()
{
	long i,n;
	double pi,di;
	printf("输入求 pi 近似值的迭代次数：\n");
	scanf("%ld",&n);
	pi=2.0;
	di=1.0;
	for(i=1;i<=n;i++)
	{
		pi*=4*di*di/(2*di-1)/(2*di+1);
		di+=1;
	}
	printf("经过%ld 次的迭代，pi 的近似值为:%.15f\n",n,pi);
	return 0;
}
