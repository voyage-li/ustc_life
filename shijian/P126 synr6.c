#include<stdio.h>
int main()
{
	int t,left=0,right=14,mid;
	int a[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	printf("请输入一个数：\n");
	scanf("%d",&t);
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==t)
		{
			printf("%d",mid+1);
			return 0;
		}
		else if(a[mid]>t)
			right=mid-1;
		else if(a[mid]<t)
			left=mid+1;
	}
 	printf("无此数！\n");
	return -1;
}
