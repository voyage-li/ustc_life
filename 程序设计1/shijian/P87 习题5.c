#include<stdio.h>
int main() 
{
	int score,x;
	printf("«Î ‰»Î≥…º®£∫");
	scanf("%d",&score);
	x=score/10;
	if(score<0||score>100)
		printf("¥ÌŒÛ£°\n");
	else
	{
		switch(x)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5: printf("%d E\n",score); break;
			case 6: printf("%d D\n",score); break;
			case 7: printf("%d C\n",score); break;
			case 8: printf("%d B\n",score); break;
			case 9: printf("%d A\n",score); break;
			case 10: printf("%d A\n",score); break;
		}
	}
	return 0;
}
