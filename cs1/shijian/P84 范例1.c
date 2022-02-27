#include<Stdio.h>
int main()
{
	int yy,mm,len;
	printf("year,month:");
	scanf("%d%d",&yy,&mm);
	switch(mm)
	{
		case 1:
		case 3:
		case 5: 
		case 7:
		case 8:
		case 10:
		case 12:len=31;break;
		case 4:
		case 6:
		case 9:
		case 11:len=30;break;
		case 2: if(yy%4==0&&yy%100!=0||yy%400==0)
					len=29;
				else
					len=28;
				break;
		default:printf("input error");
				break;
	}
	printf("The length of %d is %d\n",mm,len);
	return 0;
}
