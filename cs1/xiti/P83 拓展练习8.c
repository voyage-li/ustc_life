#include<stdio.h>
int a,b,c,d,mid; 
int a_,b_,c_,d_;
int i,j;
char signal_1,signal_2,signal_3,signal_4,signal_5,signal_6;
void begin()
{
	printf("��ʮ�ĵ�\n�������ĸ���\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
}
void calculate()
{

}
void change()
{
	mid=a;
	a=b;
	b=c;
	c=d;
	d=mid;
}
void exchange1()
{
	a=a_;b=b_;c=d_;d=c_; 
}
void exchange2()
{
	a=a_;b=c_;c=b_;d=d_; 
}
void exchange3()
{
	a=a_;b=c_;c=d_;d=b_; 
}
void exchange4()
{
	a=a_;b=d_;c=b_;d=c_; 
}
void exchange5()
{
	a=a_;b=d_;c=c_;d=b_; 
}
int main()
{
	begin();
	a_=a;b_=b;c_=c;d_=d;
	for(i=0;i<4;i++)
	{
		calculate();
		change();
	}
	exchange1();
	for(i=0;i<4;i++)
	{
		calculate();
		change();
	}
	exchange2();
	for(i=0;i<4;i++)
	{
		calculate();
		change();
	}
	exchange3();
	for(i=0;i<4;i++)
	{
		calculate();
		change();
	}
	exchange4();
	for(i=0;i<4;i++)
	{
		calculate();
		change();
	}
	exchange5();
	for(i=0;i<4;i++)
	{
		calculate();
		change();
	}
	return 0;
}



