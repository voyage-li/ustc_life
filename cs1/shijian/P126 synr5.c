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
		for(j=i+1;j<10;j++)
		{
			if(a[i].score<a[j].score)
			{
				temp=a[i].score;
				a[i].score=a[j].score;
				a[j].score=temp;
				temp=a[i].xvhao;
				a[i].xvhao=a[j].xvhao;
				a[j].xvhao=temp;
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
