#include<stdio.h>
#define PI 3.1415926
int main()
{
	double r,Volume;
	printf("请输入球的半径r\n");
	scanf("%lf",&r);
	Volume=4.0/3*PI*r*r*r;
	printf("球的体积是%lf\n",Volume);
	return 0;
}
