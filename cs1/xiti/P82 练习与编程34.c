#include<stdio.h>
#include<math.h>
int a,b,c,d,e,f,num_1,num_2,num_3;
int main()
{
	for(a=0;a<10;a++)
		for(b=0;b<10;b++)
			for(c=0;c<10;c++)
				for(d=0;d<10;d++)
					for(e=0;e<10;e++)
						for(f=0;f<10;f++)
						{
							num_1=100000*a+10000*b+1000*c+100*d+10*e+f;
							num_2=100*d+10*e+f;
							num_3=100*a+10*b+c;
							if(sqrt(num_1)-abs((sqrt(num_1)))==0&&sqrt(num_2)-abs((sqrt(num_2)))==0&&sqrt(num_3)-abs((sqrt(num_3)))==0&&a!=0)
								printf("%d%d%d%d%d%d\n",a,b,c,d,e,f);
						}
	return 0;
} 
