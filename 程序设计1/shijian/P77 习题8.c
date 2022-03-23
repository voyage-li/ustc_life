#include<stdio.h>
#include<math.h> 
#define PI 3.1415926
int main()
{
	double r,h,C,S_bottom,S_side,Volume;
	printf("请输入圆锥体的半径和高:\n"); 
	scanf("%lf %lf",&r,&h);
	C=PI*r*2;
	S_bottom=PI*r*r;
	S_side=sqrt(pow(r,2)+pow(h,2))*0.5*C;
	Volume=1.0/3*S_bottom*h;
	printf("底圆周长为%-.2f\n底面积为%-.2f\n侧面积为%-.2f\n体积为%-.2f\n",C,S_bottom,S_side,Volume);
	return 0;
 } 
