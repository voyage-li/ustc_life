#include<stdio.h>
int main()
{
	int x[4][4],i,j;
	long djh=0,djj=1,kbh=0,bkbh=0,kbj=1,bkbj=1;
	for(i=0;i<4;i++)
	{	printf("请输入第%d行:",i+1);
		for(j=0;j<4;j++)
			scanf("%d",&x[i][j]);
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(i==j||i+j==3)
			{
				djh+=x[i][j];
				djj+=x[i][j];
			}
			if(i==0||i==3||j==0||j==3)
			{
				kbh+=x[i][j];
				kbj*=x[i][j];
			} 
			if(i!=0&&i!=3&&j!=0&&j!=3)
			{
				bkbh+=x[i][j];
				bkbj*=x[i][j]; 
			}
		}
	printf("对角线元素和=%ld,对角线元素积=%ld\n",djh,djj);
	printf("靠边元素的和=%ld,靠边元素的积=%ld\n",kbh,kbj);
	printf("不靠边元素的和=%ld,不靠边元素的积=%ld\n",bkbh,bkbj);
}
