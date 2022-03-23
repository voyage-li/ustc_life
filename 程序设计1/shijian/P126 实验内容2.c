#include<stdio.h>
int main()
{
	char a[21],c;
	int i=0,m,x,temp;
	printf("请输入不超过二十个整数\n");
	for(i=0;i<=21;i++)
	{
		scanf("%d",&a[i]);
		if((c=getchar())=='\n')
			break;
	}
	temp=i;
	printf("请输入m:\n");
	scanf("%d",&m);
	printf("请输入整数：\n");
	scanf("%d",&x);
	for(;i>=m;i--)
		a[i+1]=a[i];
	a[m]=x;
	for(i=0;i<=temp+1;i++)
		printf("%d ",a[i]);
	return 0;
}
