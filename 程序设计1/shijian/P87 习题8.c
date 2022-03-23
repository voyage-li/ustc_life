#include<stdio.h>
int main()
{
	char x;
	printf("请输入字母：");
	x=getchar();
	if(x>=97&&x<=122)
	{
		x=x-'a'+'A';
		goto add;
	}
	else if(x>=65&&x<=90)
	{
		add:
 		switch(x)
		{
			case 65:
			case 79:
			case 69:
			case 73:
			case 85:printf("Yes\n");break;
			default:printf("No\n");
		}
	}
	else
	{
		printf("输入的不是字母！\n");
		goto pdd;
	} 
	printf("%d  %d",x,x+32);
	pdd:return 0;	
}
