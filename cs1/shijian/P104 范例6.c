#include<stdio.h>
void judge(int x)
{
	if(x==0)
		printf("²»ÊÇ×ï·¸\n");
	else
		printf("ÊÇ×ï·¸\n");
}
int main()
{
	int cc1,cc2,cc3,cc4,cc5,cc6;
	int a,b,c,d,e,f;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				for(d=0;d<=1;d++)
					for(e=0;e<=1;e++)
						for(f=0;f<=1;f++)
						{
							cc1=a||b;
							cc2=!(a&&f);
							cc3=(a&&e)||(a&&f)||(e&&f);
							cc4=(b&&c)||(!b&&!c);
							cc5=(c&&!d)||(d&&!c);
							cc6=d||!e;
							if(cc1&&cc2&&cc3&&cc4&cc5&&cc6)
							{
								printf("A:");judge(a);
								printf("B:");judge(b);
								printf("C:");judge(c);
								printf("D:");judge(d);
								printf("E:");judge(e);
								printf("F:");judge(f);
							} 
						} 
}
