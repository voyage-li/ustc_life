#include<stdio.h>
#include<math.h>
#define LENGTH 50.0
#define WIDTH 25.0
#define V1 0.8
#define V2 1.2
int main()
{
	float x=0.0,time,temp,dx=0;
	time=32768;
	while(x<=50.0)
	{
		temp=x/V2+sqrt(WIDTH*WIDTH+(LENGTH-x)*(LENGTH-x))/V1;
		if(temp<=time)
		{
			time=temp;
			dx=x;
		}
		x=x+0.1;
	} 
	printf("time sec=%f,x=%f\n",time,dx);
	printf("(50+25)/1.2=%f\n",(LENGTH+WIDTH)/V2);  
}
