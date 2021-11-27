#include<stdio.h>
int main()
{
	int m,n,r,max,min,mm,nn,temp,pemt;
	r=1;
	printf("求最大公约数和最小公倍数\n请输入两个正整数：\n");
	scanf("%d%d",&m,&n);
	if(m<n) 
	{
		temp=m;
		m=n;
		n=temp;
	}
	mm=m;
	nn=n;
	while(r!=0)
	{
		r=m%n;
		m=n;
		pemt=n;
		n=r;
	}
	n=pemt;
	max=n;
	min=mm*nn/max;
	printf("最大公约数为%d  最小公倍数为%d\n",max,min);
	return 0;
}
