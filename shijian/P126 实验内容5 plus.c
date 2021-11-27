#include<stdio.h>
struct student
{
	char name[20];
	int score;
	int xvhao;
};
int i,j,temp;
int main()
{
	struct student a[10];
	printf("请输入学生的姓名和成绩\n");
	for(i=0;i<10;i++)
	{
		scanf("%s %d",&a[i].name,&a[i].score);
		getchar();
	}
	for(i=0;i<10;i++)
	{
		a[i].xvhao=i;
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			if(a[j+1].score>a[j].score)
			{
				temp=a[j].score;
				a[j].score=a[j+1].score;
				a[j+1].score=temp;
				temp=a[j].xvhao;
				a[j].xvhao=a[j+1].xvhao;
				a[j+1].xvhao=temp;
			}
		}
	}
	printf("\n\n");
	for(i=0;i<10;i++)
	{
		printf("%s %d\n",a[a[i].xvhao].name,a[i].score);
	}
	return 0;
}