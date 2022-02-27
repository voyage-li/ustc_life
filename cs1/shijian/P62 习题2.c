#include<stdio.h>
#define PI 3.1415926
int main()
{
	float R,H,Volume;
	printf("请依次输入圆柱体的半径R和高H:\n");
	scanf("%f %f",&R,&H);
	if(R>0&&H>0)
	{ 
		Volume=PI*R*R*H;
		printf("圆柱体的体积Volume=%f\n",Volume);
	}
	else
		printf("Erorr!\n"); 
	return 0;
 } 
