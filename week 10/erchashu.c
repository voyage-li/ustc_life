#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
typedef struct _Student
{
	char name[51];			// 姓名
	char id[7];				// 学号，可以以0开头，定长6位
	int score;				// 成绩，[0,100]之间
	struct _Student *left;	// 左子树
	struct _Student *right; // 右子树
} STUDENT;

int compare(STUDENT *a, STUDENT *b)
{
	// 比较函数，a>b则返回正数，a==b返回0，a<b返回负数
	return strcmp(a->id, b->id); // 题目保证不同的学生会有不同的id
}

STUDENT *create(STUDENT *root, STUDENT p) //二叉查找树的建立
{

	if (root == NULL)
	{
		root = (STUDENT *)malloc(sizeof(STUDENT));
		*root = p;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (compare(&p, root) < 0)
		root->left = create(root->left, p);
	else
		root->right = create(root->right, p);
	return root;
}

void output(STUDENT *root) //输出排序后的结果，以此往后寻找最小的值，直到左子树的值为空时即为当前情况的最小值，再去寻找右子树
{
	if (root == NULL)
		return;
	output(root->left);
	printf("%s %s %d\n", root->name, root->id, root->score);
	if (root->right != NULL)
		output(root->right);
}

void search(STUDENT *root, char s[], int number) //查找
{
	if (root == NULL) //二叉树已经遍历结束，并没有找到
		printf("%s %d NOT FOUND\n", s, number - 1);
	else
	{
		if (strcmp(root->id, s) == 0) //找到
		{
			printf("%s %d %d\n", s, number, root->score);
			return;
		}
		//根据当前的id选择往左还是往右查找
		else if (strcmp(root->id, s) > 0)
			search(root->left, s, number + 1);
		else
			search(root->right, s, number + 1);
	}
}

int main()
{

	scanf("%d %d", &n, &m); //读取n,m
	STUDENT *root;
	STUDENT data[n];
	for (int i = 0; i < n; i++)
		scanf("%s %s %d", data[i].name, data[i].id, &data[i].score);
	root = NULL;
	for (int i = 0; i < n; i++)
		root = create(root, data[i]); //建立二叉查找树

	output(root); //输出排序好的顺序

	char search_data[m][7];
	for (int i = 0; i < m; i++)
		scanf("%s", search_data[i]);
	for (int i = 0; i < m; i++) //查找
		search(root, search_data[i], 1);
	return 0;
}