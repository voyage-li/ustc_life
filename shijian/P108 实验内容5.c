#include<stdio.h>
int main()
{
	long long int n,i;
	double Pi=2.0; 
	printf("计算Pi的值\n");
	printf("请输入精确度：\n");
	scanf("%ld",&n);
	for(i=1;i<n;i++)
		Pi=Pi*(2*i)*(2*i)/((2*i-1)*(2*i+1));
	printf("Pi的近似值是%lf",Pi);
	return 0;
}
