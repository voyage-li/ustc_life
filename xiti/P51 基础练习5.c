#include<stdio.h>
#include<math.h>
int main()
{
	float x,y;
	printf("请依次输入横坐标和纵坐标\n");
	scanf("%f%f",&x,&y);
	if(fabs(x)<=1&&fabs(y)<=1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
} 
