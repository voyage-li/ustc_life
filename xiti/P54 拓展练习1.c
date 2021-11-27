#include<stdio.h>
int main()
{
	int n,x,y,i,j;
	printf("你买了一箱 n 个苹果，很不幸的是买完时箱子里混进了一条虫子。虫子每 x 小时能吃掉一个苹果，假设虫子在吃完一个苹果之前不会吃另一个，那么经过 y 小时你还有多少个完整的苹果？\n");
	scanf("%d%d%d",&n,&x,&y);
	if(y>n*x)
		printf("False!\n");
	else
	{
		if(y%x==0)
		{
			i=y/x;
			j=n-i;
		}
		else
		{
			i=y/x+1;
			j=n-i;
		}
		printf("%d",j);
	}
	return 0;
} 
