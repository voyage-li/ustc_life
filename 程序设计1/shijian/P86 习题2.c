#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,p,S;
	printf("请输入三角形的三边长：\n");
	scanf("%f%f%f",&a,&b,&c);
	if(a>0&&b>0&&c>0)
	{
		if(a+b>c&&a+c>b&&b+c>a)
		{ 
			if(a==b&&b==c)
				printf("等边三角形\n");
			if((a==b&&a!=c)||(a==c&&a!=b)||(b==c&&b!=a))
				printf("等腰三角形\n");
			if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)
				printf("直角三角形\n");
			p=(a+b+c)/2;
			S=sqrt(p*(p-a)*(p-b)*(p-c));
			printf("三角形的面积是%f\n",S);
		}
		else
			printf("无法构成三角形\n");
	}
	else
		printf("DATA ERROR!\n");
	return 0;
}
