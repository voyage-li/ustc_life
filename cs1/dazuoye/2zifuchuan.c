#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a;
char *t, *v;
char Array[100][1000] = {'\0'};
char (*s)[1000] = Array;
int n, pos, m, i, j, k;
void Menu();
void select1()
{
	printf("请输入需要操作的字符串下标：\n");
	scanf("%d", &i);
}
void select2()
{
	printf("请输入需要操作的两个字符串下标（先输入s再输入t）：\n");
	scanf("%d%d", &i, &j);
}
void select3()
{
	printf("请输入需要操作的两个字符串下标（先输入s再输入t）：\n");
	scanf("%d%d", &i, &j);
	printf("请输入字符串s的下标pos:\n");
	scanf("%d", &pos);
}
void select4()
{
	printf("请输入需要操作的两个字符串下标（先输入s再输入t）：\n");
	scanf("%d%d", &i, &j);
	printf("请输入字符串s的下标pos:\n");
	scanf("%d", &pos);
	printf("请输入n\n");
	scanf("%d", &n);
}
void select5()
{
	printf("请输入需要操作的三个字符串下标（先输入s再输入v最后输入t）：\n");
	scanf("%d%d%d", &i, &k, &j);
}
void StrGet(char *s) //输入字符串
{
	system("cls");
	printf("请输入字符串：\n");
	int luru = 0;
	char temp;
	getchar();
	while (luru < 100)
	{
		temp = getchar();
		if (temp == '\n')
			break;
		else
		{
			*(s + luru) = temp;
			luru++;
		}
	}
	*(s + luru) = '\0';
	Menu();
}
void StrPut(char *s) //显示字符串
{
	system("cls");
	printf("Array[%d]=", i);
	for (int shuchu = 0; *(s + shuchu) != '\0'; shuchu++)
		printf("%c", *(s + shuchu));
	printf("\n\n");
	printf("如果想要展示全部字符串，请输入1，返回菜单请输入0：\n");
	scanf("%d", &a);
	if (a == 0)
		Menu();
	else if (a == 1)
	{
		system("cls");
		for (int xunhuan = 0; xunhuan < 100; xunhuan++)
		{
			if (Array[xunhuan][0] != '\0')
			{
				printf("Array[%d]=", xunhuan);
				for (int xunhuan1 = 0; Array[xunhuan][xunhuan1] != '\0'; xunhuan1++)
					printf("%c", Array[xunhuan][xunhuan1]);
				printf("\n");
			}
		}
		system("pause");
		Menu();
	}
}
void StrLen(char *s) //求字符串长度：长度不包括字符串结束标志
{
	system("cls");
	int count;
	for (count = 0; *(s + count) != '\0'; count++)
		;
	printf("Array[%d]的长度为%d\n", i, count);
	system("pause");
	Menu();
}
void StrCat(char *s, char *t) //字符串连接：将t连接到s后面，结果保存在s中
{
	system("cls");
	int jisuan, zhantian;
	for (jisuan = 0; *(s + jisuan) != '\0'; jisuan++)
		;
	for (zhantian = 0; *(t + zhantian) != '\0'; (zhantian++, jisuan++))
		*(s + jisuan) = *(t + zhantian);
	printf("Array[%d]=", i);
	for (int shuchu = 0; *(s + shuchu) != '\0'; shuchu++)
		printf("%c", *(s + shuchu));
	printf("\n");
	system("pause");
	Menu();
}
void StrCmp(char *s, char *t) //字符串比较
{
	system("cls");
	int bijiao = 0, xunhuan;
	int jishu1, jishu2;
	for (jishu1 = 0; *(s + jishu1) != '\0'; jishu1++)
		;
	for (jishu2 = 0; *(t + jishu2) != '\0'; jishu2++)
		;
	if (jishu1 != jishu2)
		bijiao = -1;
	else
		for (xunhuan = 0; xunhuan < jishu1; xunhuan++)
			if (*(s + xunhuan) != *(t + xunhuan))
			{
				bijiao = -1;
				break;
			}
	if (bijiao == -1)
		printf("两个字符串不相同!\n");
	else
		printf("两个字符串相同!\n");
	system("pause");
	Menu();
}
void StrCpy(char *s, char *t) //字符串复制：将t复制到s中
{
	system("cls");
	for (int jishu1 = 0; *(s + jishu1) != '\0'; jishu1++)
		*(s + jishu1) = '\0';
	for (int jishu1 = 0; *(t + jishu1) != '\0'; jishu1++)
		*(s + jishu1) = *(t + jishu1);
	printf("Array[%d]=Array[%d]=", i, j);
	for (int jishu1 = 0; *(s + jishu1) != '\0'; jishu1++)
		printf("%c", *(s + jishu1));
	printf("\n");
	system("pause");
	Menu();
}
void StrIns(char *s, int pos, char *t) //字符串插入：将t插入到s的下标pos之前
{
	system("cls");
	int jishu1, jishu2;
	for (jishu1 = 0; *(s + jishu1) != '\0'; jishu1++)
		;
	for (jishu2 = 0; *(t + jishu2) != '\0'; jishu2++)
		;
	int houyi;
	for (houyi = jishu1 + jishu2 - 1; houyi >= pos + jishu2; houyi--)
		*(s + houyi) = *(s + houyi - jishu2);
	for (int luru = 0; luru < jishu2; luru++)
		*(s + luru + pos) = *(t + luru);
	printf("Array[%d]=", i);
	for (int xunhuan = 0; *(s + xunhuan) != '\0'; xunhuan++)
		printf("%c", *(s + xunhuan));
	printf("\n");
	system("pause");
	Menu();
}
void StrSub(char *s, int pos, int n, char *t) //求字串：求s中从下标pos开始n个字符组成的字符串，保存在t中
{
	char temp[n];
	int xunhuan = pos;
	while (xunhuan < pos + n)
	{
		temp[xunhuan - pos] = *(s + xunhuan);
		xunhuan++;
	}
	for (xunhuan = 0; xunhuan < n; xunhuan++)
		*(t + xunhuan) = temp[xunhuan];
	printf("Array[%d]=", j);
	for (xunhuan = 0; *(t + xunhuan) != '\0'; xunhuan++)
		printf("%c", *(t + xunhuan));
	printf("\n");
	system("pause");
	Menu();
}
void StrStr(char *s, char *t) //子串查找：求t在s中第一次出现的位置下标，不存在则返回-1
{
	system("cls");
	int jishu1, jishu2;
	for (jishu1 = 0; *(s + jishu1) != '\0'; jishu1++)
		;
	for (jishu2 = 0; *(t + jishu2) != '\0'; jishu2++)
		;
	int xunhuan1, xunhuan2, temp, jilu;
	for (xunhuan1 = 0; xunhuan1 < jishu1; xunhuan1++)
	{
		jilu = xunhuan1;
		temp = 0;
		for (xunhuan2 = 0; xunhuan2 < jishu2; xunhuan2++)
		{
			if (*(s + xunhuan1) == *(t + xunhuan2))
			{
				temp++;
				xunhuan1++;
			}
			else
			{
				break;
			}
		}
		xunhuan1 = jilu;
		if (temp == jishu2)
			break;
	}
	if (temp == jishu2)
		printf("Array[%d]在Array[%d]第一次出现在下标%d处\n", j, i, jilu);
	else
		printf("Array[%d]中不存在Array[%d]\n", i, j);
	system("pause");
	Menu();
}
int zailai(char *s, char *v, char *t, int pos)
{
	int jishu1, jishu2, jishu3;
	for (jishu1 = 0; *(s + jishu1) != '\0'; jishu1++)
		;
	for (jishu2 = 0; *(v + jishu2) != '\0'; jishu2++)
		;
	for (jishu3 = 0; *(t + jishu3) != '\0'; jishu3++)
		;
	int xunhuan1, xunhuan2, temp, jilu;
	for (xunhuan1 = pos; xunhuan1 < jishu1; xunhuan1++)
	{
		jilu = xunhuan1;
		temp = 0;
		for (xunhuan2 = 0; xunhuan2 < jishu2; xunhuan2++)
		{
			if (*(s + xunhuan1) == *(v + xunhuan2))
			{
				temp++;
				xunhuan1++;
			}
			else
				break;
		}
		xunhuan1 = jilu;
		if (temp == jishu2)
			break;
	}
	if (temp == jishu2)
	{
		char TEMPstring[100];
		for (xunhuan2 = jilu + jishu2; xunhuan2 < jishu1; xunhuan2++)
			TEMPstring[xunhuan2 - jilu - jishu2] = *(s + xunhuan2);
		for (xunhuan1 = 0; xunhuan1 < jishu3; xunhuan1++)
			*(s + jilu + xunhuan1) = *(t + xunhuan1);
		for (xunhuan1 = jishu3 + jilu; xunhuan1 < jishu1 + jishu3 - jishu2; xunhuan1++)
			*(s + xunhuan1) = TEMPstring[xunhuan1 - jishu3 - jilu];
		return 1;
	}
	else
		return 0;
}
void StrReplace(char *s, char *v, char *t) //子串置换（选做）：将s中出现的v用t置换
{
	system("cls");
	int jishu1, jishu2, jishu3, daxunhuan = 1;
	for (jishu1 = 0; *(s + jishu1) != '\0'; jishu1++)
		;
	for (jishu2 = 0; *(v + jishu2) != '\0'; jishu2++)
		;
	for (jishu3 = 0; *(t + jishu3) != '\0'; jishu3++)
		;
	int xunhuan1, xunhuan2, temp, jilu;
	for (xunhuan1 = 0; xunhuan1 < jishu1; xunhuan1++)
	{
		jilu = xunhuan1;
		temp = 0;
		for (xunhuan2 = 0; xunhuan2 < jishu2; xunhuan2++)
		{
			if (*(s + xunhuan1) == *(v + xunhuan2))
			{
				temp++;
				xunhuan1++;
			}
			else
				break;
		}
		xunhuan1 = jilu;
		if (temp == jishu2)
			break;
	}
	if (temp == jishu2)
	{
		char TEMPstring[100];
		for (xunhuan2 = jilu + jishu2; xunhuan2 < jishu1; xunhuan2++)
			TEMPstring[xunhuan2 - jilu - jishu2] = *(s + xunhuan2);
		for (xunhuan1 = 0; xunhuan1 < jishu3; xunhuan1++)
			*(s + jilu + xunhuan1) = *(t + xunhuan1);
		for (xunhuan1 = jishu3 + jilu; xunhuan1 < jishu1 + jishu3 - jishu2; xunhuan1++)
			*(s + xunhuan1) = TEMPstring[xunhuan1 - jishu3 - jilu];
		while (daxunhuan == 1)
			daxunhuan = zailai(s, v, t, jilu + jishu3);
		printf("Array[%d]=", i);
		for (xunhuan1 = 0; *(s + xunhuan1) != '\0'; xunhuan1++)
			printf("%c", *(s + xunhuan1));
	}
	else
		printf("Array[%d]中不存在Array[%d]\n", i, k);
	printf("\n");
	system("pause");
	Menu();
}
void Zixvan() //自选功能
{
	system("cls");
	printf("无其他自选功能，因为懒！\n");
	system("pause");
	Menu();
}
void Menu() //主菜单
{
	system("cls");
	printf("菜单\n");
	printf("- 0 退出程序\n");
	printf("- 1 输入字符串\n");
	printf("- 2 显示字符串\n");
	printf("- 3 求字符串长度：长度不包括字符串结束标志\n");
	printf("- 4 字符串连接：将t连接到s后面，结果保存在s中\n");
	printf("- 5 字符串比较\n");
	printf("- 6 字符串复制：将t复制到s中\n");
	printf("- 7 字符串插入：将t插入到s的下标pos之前\n");
	printf("- 8 求字串：求s中从下标pos开始n个字符组成的字符串，保存在t中\n");
	printf("- 9 子串查找：求t在s中第一次出现的位置下标，不存在则返回-1\n");
	printf("-10 子串置换：将s中出现的v用t置换（选做）\n");
	printf("-11 其他自选功能\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		exit(0);
	case 1:
		select1();
		StrGet(*(s + i));
	case 2:
		select1();
		StrPut(*(s + i));
	case 3:
		select1();
		StrLen(*(s + i));
	case 4:
		select2();
		StrCat(*(s + i), *(s + j));
	case 5:
		select2();
		StrCmp(*(s + i), *(s + j));
	case 6:
		select2();
		StrCpy(*(s + i), *(s + j));
	case 7:
		select3();
		StrIns(*(s + i), pos, *(s + j));
	case 8:
		select4();
		StrSub(*(s + i), pos, n, *(s + j));
	case 9:
		select2();
		StrStr(*(s + i), *(s + j));
	case 10:
		select5();
		StrReplace(*(s + i), *(s + k), *(s + j));
	case 11:
		Zixvan();
	default:
		Menu();
	}
}
int main() //主函数
{
	Menu();
	return 0;
}