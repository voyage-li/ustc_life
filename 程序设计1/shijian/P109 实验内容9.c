
#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,r,next=0,sum=0;
	int a[100];
	for(i=1;i<500;i=i+2)
	{
		for(j=3;j<sqrt(i);j=j+2)
		{
			r=i%j;
			if(r==0)
				break;
		}
		if(r!=0)
		{
			a[next]=i;
			next++;
		}
	}
	if(next<10)
		printf("不足十个素数\n");
	else
	{
		for(i=0;i<=10;i++)
		{
			sum=sum+a[next];
			next--;
		}
		next=next+11;
		for(i=0;i<9;i++)
		{
			next--;
			printf("%d+",a[next]);
		}
		printf("%d=",a[next-1]); 
		printf("%d\n",sum);
	} 
}
