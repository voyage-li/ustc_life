#include<stdio.h>
int main()
{
	int i_minuend,i_subtrahend,i_difference;
	printf("请输入被减数及减数\n");
	scanf("%d",&i_minuend);
	scanf("%d",&i_subtrahend);
	i_difference=i_minuend-i_subtrahend;
	printf("%d-%d=%d\n",i_minuend,i_subtrahend,i_difference);
	return 0;
} 
