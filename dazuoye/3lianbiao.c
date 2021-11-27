#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int a;
struct student
{
	int number;
	char name[25];
	char sex;
	int age;
	float score;
	struct student *next;
};
struct student *head, *rear;
void Menu();
struct student *Headcreat() //头插法
{
	system("cls");
	struct student *p, *head, *rear;
	p = head = rear = NULL;
	while (1)
	{
		system("cls");
		p = (struct student *)malloc(sizeof(struct student));
		printf("请输入学生的学号：");
		scanf("%d", &p->number);
		printf("请输入学生的姓名：");
		scanf("%s", p->name);
		getchar();
		printf("请输入学生的性别（f or m）：");
		scanf("%c", &p->sex);
		printf("请输入学生的年龄：");
		scanf("%d", &p->age);
		printf("请输入学生的成绩：");
		scanf("%f", &p->score);
		if (rear == NULL)
			rear = p;
		else
			p->next = head;
		head = p;
		printf("输入0退出循环，输入其他数字继续循环：");
		scanf("%d", &a);
		if (a == 0)
		{
			rear->next = NULL;
			break;
		}
	}
	return head;
}
struct student *Rearcreat() //尾插法
{
	system("cls");
	struct student *p, *head, *rear;
	p = head = rear = NULL;
	while (1)
	{
		system("cls");
		p = (struct student *)malloc(sizeof(struct student));
		printf("请输入学生的学号：");
		scanf("%d", &p->number);
		printf("请输入学生的姓名：");
		scanf("%s", p->name);
		getchar();
		printf("请输入学生的性别（f or m）：");
		scanf("%c", &p->sex);
		printf("请输入学生的年龄：");
		scanf("%d", &p->age);
		printf("请输入学生的成绩：");
		scanf("%f", &p->score);
		if (head == NULL && rear == NULL)
			rear = head = p;
		else
			rear->next = p;
		rear = p;
		printf("输入0退出循环，输入其他数字继续循环：");
		scanf("%d", &a);
		if (a == 0)
		{
			rear->next = NULL;
			break;
		}
	}
	return head;
}
struct student *NumberCreat() //创建按学号有序链表
{
	system("cls");
	struct student *p, *q, *head, *rear;
	p = q = head = rear = NULL;
	while (1)
	{
		system("cls");
		p = (struct student *)malloc(sizeof(struct student));
		printf("请输入学生的学号：");
		scanf("%d", &p->number);
		printf("请输入学生的姓名：");
		scanf("%s", p->name);
		getchar();
		printf("请输入学生的性别（f or m）：");
		scanf("%c", &p->sex);
		printf("请输入学生的年龄：");
		scanf("%d", &p->age);
		printf("请输入学生的成绩：");
		scanf("%f", &p->score);
		if (head == NULL && rear == NULL)
			rear = head = p;
		else
			rear->next = p;
		rear = p;
		printf("输入0退出循环，输入其他数字继续循环：");
		scanf("%d", &a);
		if (a == 0)
		{
			rear->next = NULL;
			break;
		}
	}
	int i, n, j;
	p = head;
	for (n = 0; p != NULL; n++)
		p = p->next;
	struct student s[n];
	p = head;
	for (i = 0; i < n; i++)
	{
		strcpy(s[i].name, p->name);
		s[i].age = p->age;
		s[i].next = p->next;
		s[i].number = p->number;
		s[i].score = p->score;
		s[i].sex = p->sex;
		p = p->next;
	}
	struct student temp;
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (s[i].number > s[j].number)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
	head = rear = NULL;
	for (i = 0; i < n; i++)
	{
		system("cls");
		p = (struct student *)malloc(sizeof(struct student));
		p->number = s[i].number;
		p->sex = s[i].sex;
		p->age = s[i].age;
		p->score = s[i].score;
		strcpy(p->name, s[i].name);
		if (head == NULL && rear == NULL)
			rear = head = p;
		else
			rear->next = p;
		rear = p;
	}
	rear->next = NULL;
	return head;
}
struct student *Filecreat() //打开学生信息文件创建链表
{
	system("cls");
	struct student *p;
	FILE *fp;
	if ((fp = fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\xueshengshujv.dat", "r+")) == NULL)
	{
		printf("文件未能成功打开！\n");
		system("pause");
		Menu();
	}
	while (!feof(fp))
	{
		p = (struct student *)malloc(sizeof(struct student));
		fscanf(fp, "%d %s %c %d %f", &p->number, p->name, &p->sex, &p->age, &p->score);
		if (head == NULL && rear == NULL)
			rear = head = p;
		else
			rear->next = p;
		rear = p;
	}
	rear->next = NULL;
	return head;
}
void Creat() //创建学生记录链表
{
	system("cls");
	printf("-0 返回上一级菜单\n");
	printf("-1 头插法\n");
	printf("-2 尾插法\n");
	printf("-3 创建按学号有序链表\n");
	printf("-4 打开学生信息文件创建链表\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu();
	case 1:
		head = Headcreat();
		Menu();
	case 2:
		head = Rearcreat();
		Menu();
	case 3:
		head = NumberCreat();
		Menu();
	case 4:
		head = Filecreat();
		Menu();
	default:
		Creat();
	}
}
void Printall(struct student *head) //打印全部学生记录
{
	system("cls");
	struct student *p;
	p = head;
	while (p != NULL)
	{
		printf("%3d\t%-11s\t%c\t%d\t%f\n", p->number, p->name, p->sex, p->age, p->score);
		p = p->next;
	}
	system("pause");
	Menu();
}
struct student *PosInsert(struct student *head) //按指定位序插入
{
	system("cls");
	int i;
	printf("请输入指定位置：");
	scanf("%d", &a);
	struct student *p, *q, *insert;
	p = head;
	insert = (struct student *)malloc(sizeof(struct student));
	printf("请输入学生的学号：");
	scanf("%d", &insert->number);
	printf("请输入学生的姓名：");
	scanf("%s", insert->name);
	getchar();
	printf("请输入学生的性别（f or m）：");
	scanf("%c", &insert->sex);
	printf("请输入学生的年龄：");
	scanf("%d", &insert->age);
	printf("请输入学生的成绩：");
	scanf("%f", &insert->score);
	if (a == 0)
	{
		insert->next = head;
		head = insert;
		return head;
	}
	for (i = 0; i < a - 1; i++)
		p = p->next;
	q = p->next;
	p->next = insert;
	insert->next = q;
	return head;
}
struct student *ArrInsert(struct student *head) //在有序链表中插入
{
	system("cls");
	int sheng = 0, jiang = 0;
	struct student *p, *q, *insert;
	p = head;
	while (p->next != NULL)
	{
		if (p->number > p->next->number)
			jiang++;
		if (p->number < p->next->number)
			sheng++;
		p = p->next;
	}
	if ((sheng != 0 && jiang == 0) || (sheng == 0 && jiang != 0) || (sheng == 0 && jiang == 0))
	{
		insert = (struct student *)malloc(sizeof(struct student));
		printf("请输入学生的学号：");
		scanf("%d", &insert->number);
		printf("请输入学生的姓名：");
		scanf("%s", insert->name);
		getchar();
		printf("请输入学生的性别（f or m）：");
		scanf("%c", &insert->sex);
		printf("请输入学生的年龄：");
		scanf("%d", &insert->age);
		printf("请输入学生的成绩：");
		scanf("%f", &insert->score);
		p = head;
		int jilu = 0;
		while (p->next != NULL)
		{
			if (sheng != 0 && insert->number >= p->number && insert->number <= p->next->number)
			{
				q = p->next;
				p->next = insert;
				insert->next = q;
				jilu = 7;
				break;
			}
			if (jiang != 0 && insert->number <= p->number && insert->number >= p->next->number)
			{
				q = p->next;
				p->next = insert;
				insert->next = q;
				jilu = 7;
				break;
			}
			if (sheng != 0 && insert->number <= p->number)
			{
				insert->next = head;
				head = insert;
				jilu = 7;
				break;
			}
			if (jiang != 0 && insert->number >= p->number)
			{
				insert->next = head;
				head = insert;
				jilu = 7;
				break;
			}
			p = p->next;
		}
		if (jilu != 7)
		{
			p->next = insert;
			insert->next = NULL;
		}
		return head;
	}
	else
	{
		printf("链表不是有序的！\n");
		system("pause");
		return head;
	}
}
void Insert() //插入一条新的学生记录
{
	system("cls");
	printf("-0 返回上一级菜单\n");
	printf("-1 按指定位序插入\n");
	printf("-2 在有序链表中插入\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu();
	case 1:
		head = PosInsert(head);
		Menu();
	case 2:
		head = ArrInsert(head);
		Menu();
	default:
		Insert();
	}
}
struct student *PosDelete(struct student *head) //删除指定位置的记录
{
	system("cls");
	system("cls");
	printf("请输入指定位置：");
	scanf("%d", &a);
	struct student *p, *q;
	p = head;
	int n;
	for (n = 0; p != NULL; n++)
		p = p->next;
	p = head;
	if (a == 1)
		head = head->next;
	else if (a == n)
	{
		for (int i = 0; i < n - 2; i++)
			p = p->next;
		p->next = NULL;
	}
	else
	{
		for (int i = 0; i < a - 2; i++)
			p = p->next;
		q = p->next->next;
		p->next = q;
	}
	return head;
}
struct student *NumDelete(struct student *head) //删除指定学号的记录
{
	system("cls");
	struct student *p, *q;
	p = head;
	printf("请输入指定的学号：");
	scanf("%d", &a);
	int pos, jilu = 0;
	for (pos = 0; p != NULL; pos++)
	{
		if (a == p->number)
		{
			jilu++;
			break;
		}
		q = p;
		p = p->next;
	}
	if (pos == 0)
		head = head->next;
	else if (jilu != 0 && p->next == NULL)
		q->next = NULL;
	else if (jilu == 0)
	{
		printf("没有此学号学生的记录！\n");
		system("pause");
	}
	else
		q->next = p->next;
	return head;
}
void Delete() //按条件删除一条学生记录
{
	system("cls");
	printf("-0 返回上一级菜单\n");
	printf("-1 删除指定位置的记录\n");
	printf("-2 删除指定学号的记录\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu();
	case 1:
		head = PosDelete(head);
		Menu();
	case 2:
		head = NumDelete(head);
		Menu();
	default:
		Delete();
	}
}
void Find(struct student *head) //按学号查找学生记录
{
	system("cls");
	struct student *p;
	p = head;
	printf("请输入指定的学号：");
	scanf("%d", &a);
	int jilu = 0;
	for (int i = 0; p != NULL; i++)
	{
		if (a == p->number)
		{
			jilu++;
			break;
		}
		p = p->next;
	}
	if (jilu != 0)
		printf("%3d\t%-11s\t%c\t%d\t%f\n", p->number, p->name, p->sex, p->age, p->score);
	else
		printf("没有此学号学生的记录！\n");
	system("pause");
	Menu();
}
void StuSta(struct student *head) //统计学生人数
{
	system("cls");
	struct student *p;
	p = head;
	int n;
	for (n = 0; p != NULL; n++)
		p = p->next;
	printf("总人数为%d人\n", n);
	system("pause");
	Menu();
}
void AveMax(struct student *head) //统计学生的平均成绩和最高分
{
	system("cls");
	int i;
	struct student *p;
	float max = 0, average = 0, jilu;
	p = head;
	max = p->score;
	for (i = 0; p != NULL; i++)
	{
		average += p->score;
		if (max < p->score)
		{
			jilu = i;
			max = p->score;
		}
		p = p->next;
	}
	average = average / i;
	p = head;
	for (i = 0; i < jilu; i++)
		p = p->next;
	printf("平均分为：%f\n", average);
	printf("最高分为：\n%3d\t%-11s\t%c\t%d\t%f\n", p->number, p->name, p->sex, p->age, p->score);
	system("pause");
	Menu();
}
void NotPass(struct student *head) //统计不及格人数
{
	system("cls");
	struct student *p;
	int people = 0;
	p = head;
	while (p != NULL)
	{
		if (p->score < 60)
			people++;
		p = p->next;
	}
	printf("不及格的有%d个人\n", people);
	system("pause");
	Menu();
}
void Statistics() //统计
{
	system("cls");
	printf("-0 返回上一级菜单\n");
	printf("-1 统计学生人数\n");
	printf("-2 统计学生的平均成绩和最高分\n");
	printf("-3 统计不及格人数\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu();
	case 1:
		StuSta(head);
	case 2:
		AveMax(head);
	case 3:
		NotPass(head);
	default:
		Statistics();
	}
}
struct student *Destroy(struct student *head) //销毁学生链表
{
	system("cls");
	struct student *p, *q;
	int n;
	p = head;
	for (n = 0; p != NULL; n++)
		p = p->next;
	p = head;
	for (int i = 0; i < n; i++)
	{
		q = p;
		p = p->next;
		free(q);
	}
	head = rear = NULL;
	printf("链表已销毁！\n");
	system("pause");
	return head;
}
void ReWrite() //重写学生文件
{
	system("cls");
	struct student *p;
	FILE *fp;
	if ((fp = fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\xueshengshujv.dat", "w")) == NULL)
	{
		printf("文件未能成功打开！\n");
		system("pause");
		Menu();
	}
	while (1)
	{
		system("cls");
		p = (struct student *)malloc(sizeof(struct student));
		printf("请输入学生的学号：");
		scanf("%d", &p->number);
		printf("请输入学生的姓名：");
		scanf("%s", p->name);
		getchar();
		printf("请输入学生的性别（f or m）：");
		scanf("%c", &p->sex);
		printf("请输入学生的年龄：");
		scanf("%d", &p->age);
		printf("请输入学生的成绩：");
		scanf("%f", &p->score);
		fprintf(fp, "%d %s %c %d %f", p->number, p->name, p->sex, p->age, p->score);
		printf("输入0退出录入，输入其他数字继续录入：");
		scanf("%d", &a);
		free(p);
		if (a == 0)
			break;
		else
			fprintf(fp, "\n");
	}
	printf("录入结束！\n");
	system("pause");
	Menu();
}
void AddWrite() //追加学生文件
{
	system("cls");
	system("cls");
	struct student *p;
	FILE *fp;
	if ((fp = fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\xueshengshujv.dat", "a")) == NULL)
	{
		printf("文件未能成功打开！\n");
		system("pause");
		Menu();
	}
	fprintf(fp, "\n");
	while (1)
	{
		system("cls");
		p = (struct student *)malloc(sizeof(struct student));
		printf("请输入学生的学号：");
		scanf("%d", &p->number);
		printf("请输入学生的姓名：");
		scanf("%s", p->name);
		getchar();
		printf("请输入学生的性别（f or m）：");
		scanf("%c", &p->sex);
		printf("请输入学生的年龄：");
		scanf("%d", &p->age);
		printf("请输入学生的成绩：");
		scanf("%f", &p->score);
		fprintf(fp, "%d %s %c %d %f", p->number, p->name, p->sex, p->age, p->score);
		printf("输入0退出录入，输入其他数字继续录入：");
		scanf("%d", &a);
		free(p);
		if (a == 0)
			break;
		else
			fprintf(fp, "\n");
	}
	printf("录入结束！\n");
	system("pause");
	Menu();
}
void DeleteWrite() //清空学生文件
{
	system("cls");
	FILE *fp;
	if ((fp = fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\xueshengshujv.dat", "w")) == NULL)
	{
		printf("文件未能成功打开！\n");
		system("pause");
		Menu();
	}
	else
	{
		printf("清空成功！\n");
		system("pause");
	}
	Menu();
}
void Write() //将学生信息写入磁盘文件
{
	system("cls");
	printf("-0 返回上一级菜单\n");
	printf("-1 重写学生文件\n");
	printf("-2 追加学生文件\n");
	printf("-3 清空学生文件\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu();
	case 1:
		ReWrite();
	case 2:
		AddWrite();
	case 3:
		DeleteWrite();
	default:
		Write();
	}
}
void Zixvan() //自选功能
{
	system("cls");
	printf("无其他自选功能，因为懒！\n");
	system("pause");
	Menu();
}
void Menu() //菜单
{
	system("cls");
	printf("菜单\n");
	printf("- 0 退出程序\n");
	printf("- 1 创建学生记录链表\n");
	printf("- 2 打印全部学生记录\n");
	printf("- 3 插入一条新的学生记录\n");
	printf("- 4 按条件删除一条学生记录\n");
	printf("- 5 按学号查找学生记录\n");
	printf("- 6 统计\n");
	printf("- 7 销毁学生链表\n");
	printf("- 8 将学生信息写入磁盘文件\n");
	printf("- 9 其他自选功能\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		exit(0);
	case 1:
		Creat();
	case 2:
		Printall(head);
	case 3:
		Insert();
	case 4:
		Delete();
	case 5:
		Find(head);
	case 6:
		Statistics();
	case 7:
		head = Destroy(head);
		Menu();
	case 8:
		Write();
	case 9:
		Zixvan();
	default:
		Menu();
	}
}
int main() //主函数
{
	head = rear = NULL;
	Menu();
	return 0;
}