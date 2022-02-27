#include<stdio.h>
int main()
{
	float c,f;
	printf("请输入华氏温度:\n");
	scanf("%f",&f);
	c=5.0/9*(f-32);
	printf("%f华氏度=%f摄氏度\n",f,c);
	return 0;
}
