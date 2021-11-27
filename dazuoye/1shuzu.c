#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a, i, j, temp, jiuxing;
int Length, Num_row;
int *Array;
void Menu1();
void Sort();
void Arrange();
void Config() //配置参数
{
	system("cls");
	printf("请输入数组的长度和每行输出的元素个数\n");
	scanf("%d%d", &Length, &Num_row);
	Array = (int *)malloc(Length * sizeof(int));
	for (i = 0; i < Length; i++)
		Array[i] = 1;
	Menu1();
}
void FillRandom() //用指定范围内的随机数填充数组
{
	system("cls");
	printf("请输入随机数的最小值和最大值：\n");
	int left, right;
	scanf("%d %d", &left, &right);
	for (i = 0; i < Length; i++)
		Array[i] = (float)rand() / RAND_MAX * (right - left) + left;
	Menu1();
}
void FillKeyboard() //键盘输入
{
	system("cls");
	printf("请输入%d个数\n", Length);
	for (i = 0; i < Length; i++)
	{
		scanf("%d", &Array[i]);
		getchar();
	}
	Menu1();
}
void FillSameVal() //整个数组填充同一个值
{
	system("cls");
	int same;
	printf("请输入一个数\n");
	scanf("%d", &same);
	for (i = 0; i < Length; i++)
		Array[i] = same;
	Menu1();
}
void FillArithSeq() //用等差数列填充数组
{
	system("cls");
	int first, d;
	printf("请输入等差数列的起始项和差值\n");
	scanf("%d %d", &first, &d);
	int bian;
	for (bian = 0; bian < Length; bian++)
		Array[bian] = first + d * bian;
	Menu1();
}
void FillArray() //生成样本数据
{
	system("cls");
	printf("-0 返回上一级菜单\n");
	printf("-1 用指定范围内的随机数填充数组\n");
	printf("-2 键盘输入\n");
	printf("-3 整个数组填充同一个值\n");
	printf("-4 用等差数列填充数组\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		FillRandom();
	case 2:
		FillKeyboard();
	case 3:
		FillSameVal();
	case 4:
		FillArithSeq();
	default:
		FillArray();
	}
}
void PrintArray() //显示数组
{
	system("cls");
	for (i = 0; i < Length; i++)
	{
		printf("%6d", Array[i]);
		if ((i + 1) % Num_row == 0)
			printf("\n");
	}
	printf("\n");
	system("pause");
	Menu1();
}
void DeleteIndex() //删除指定下标的元素
{
wow:
	printf("请输入指定的下标:\n");
	scanf("%d", &a);
	if (a < 0 || a >= Length)
	{
		printf("输入错误！\n");
		goto wow;
	}
	else
		for (i = a; i < Length; i++)
			Array[i] = Array[i + 1];
	Length = Length - 1;
	Menu1();
}
void DeleteRange() //删除指定下标区间的元素
{
	int left1, right1;
	printf("请输入删除的下标区间：\n");
	scanf("%d%d", &left1, &right1);
	for (i = left1; i <= right1; i++)
		Array[i] = Array[i + right1 - left1 + 1];
	Length = Length - (right1 - left1 + 1);
	Menu1();
}
void DeleteValue() //删除指定值的元素
{
	printf("请输入需要删除的元素：\n");
	int delete1 = -1;
	scanf("%d", &a);
	for (i = 0; i < Length; i++)
		if (Array[i] == a)
		{
			delete1 = i;
			break;
		}
	if (delete1 == -1)
		printf("不存在这个元素！\n");
	else
	{
		for (i = delete1; i < Length; i++)
			Array[i] = Array[i + 1];
		Length = Length - 1;
	}
	delete1 = -1;
	for (i = 0; i < Length; i++)
	{
		for (i = 0; i < Length; i++)
			if (Array[i] == a)
			{
				delete1 = i;
				break;
			}
		if (delete1 == -1)
			break;
		else
		{
			for (i = delete1; i < Length; i++)
				Array[i] = Array[i + 1];
			Length = Length - 1;
		}
	}
	Menu1();
}
void Delete() //删除
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 删除指定下标的元素\n");
	printf("-2 删除指定下标区间的元素\n");
	printf("-3 删除指定值的元素\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		DeleteIndex();
	case 2:
		DeleteRange();
	case 3:
		DeleteValue();
	default:
		Delete();
	}
	Menu1();
}
void InsertIndex() //按指定下标位置插入新元素
{
	system("cls");
	printf("请输入指定位置和元素：\n");
	int b;
	int tempArray[Length + 1];
	scanf("%d%d", &a, &b);
	for (i = 0; i < Length; i++)
		tempArray[i] = Array[i];
	Length = Length + 1;
	jiuxing = Length;
	for (i = jiuxing - 1; i >= a; i--)
		tempArray[i] = tempArray[i - 1];
	tempArray[a - 1] = b;
	Array = (int *)malloc(Length * sizeof(int));
	for (i = 0; i < Length; i++)
		Array[i] = tempArray[i];
	if (a == 0)
		Array[0] = b;
	PrintArray();
}
void InsertOrder() //在有序数组中插入新元素
{
	system("cls");
	int judgeup = 0, judgedown = 0;
	for (i = 0; i < Length - 1; i++)
	{
		if (Array[i] <= Array[i + 1])
			judgeup++;
		if (Array[i] > Array[i + 1])
			judgedown--;
	}
	if (judgeup != 0 && judgedown != 0)
	{
		printf("不是有序数组！\n");
		system("pause");
	}
	else
	{
		int tempArray[Length + 1];
		for (i = 0; i < Length; i++)
			tempArray[i] = Array[i];
		printf("请输入需要插入的数\n");
		scanf("%d", &a);
		if (judgeup != 0)
		{
			if (a <= tempArray[0])
			{
				for (i = Length + 1; i > 0; i--)
					tempArray[i] = tempArray[i - 1];
				tempArray[0] = a;
			}
			else if (a >= tempArray[Length - 1])
			{
				tempArray[Length] = a;
			}
			else
			{
				for (i = 0; i < Length; i++)
				{
					if (tempArray[i] <= a && tempArray[i + 1] >= a)
					{
						temp = i + 1;
						break;
					}
				}
				for (i = Length + 1; i > temp; i--)
					tempArray[i] = tempArray[i - 1];
				tempArray[temp] = a;
			}
		}
		if (judgedown != 0)
		{
			if (a >= tempArray[0])
			{
				for (i = Length + 1; i > 0; i--)
					tempArray[i] = tempArray[i - 1];
				tempArray[0] = a;
			}
			else if (a <= tempArray[Length - 1])
			{
				tempArray[Length] = a;
			}
			else
			{
				for (i = 0; i < Length; i++)
				{
					if (tempArray[i] >= a && tempArray[i + 1] <= a)
					{
						temp = i + 1;
						break;
					}
				}
				for (i = Length + 1; i > temp; i--)
					tempArray[i] = tempArray[i - 1];
				tempArray[temp] = a;
			}
		}
		Length = Length + 1;
		Array = (int *)malloc(Length * sizeof(int));
		for (i = 0; i < Length; i++)
		{
			Array[i] = tempArray[i];
		}
		PrintArray();
	}
}
void Insert() //插入
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 按指定下标位置插入新元素\n");
	printf("-2 在有序数组中插入新元素\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		InsertIndex();
	case 2:
		InsertOrder();
	default:
		Insert();
	}
}
void Max() //求最大值
{
	system("cls");
	int max = Array[0];
	for (i = 0; i < Length; i++)
		if (max < Array[i])
		{
			max = Array[i];
			temp = i;
		}
	printf("最大值：Array[temp]=%d\n", max);
	system("pause");
	Menu1();
}
void Min() //求最小值
{
	system("cls");
	int min = Array[0];
	for (i = 0; i < Length; i++)
		if (min > Array[i])
		{
			min = Array[i];
			temp = i;
		}
	printf("最小值：Array[temp]=%d\n", min);
	system("pause");
	Menu1();
}
void Average() //求平均值
{
	system("cls");
	float sum;
	for (i = 0; i < Length; i++)
		sum += Array[i];
	printf("平均值为%f\n", sum / (Length + 1));
	system("pause");
	Menu1();
}
void Variance() //求方差
{
	system("cls");
	float sum = 0, S = 0;
	for (i = 0; i < Length; i++)
		sum += Array[i];
	sum = sum / (Length + 1);
	for (i = 0; i < Length; i++)
		S += pow(Array[i] - sum, 2);
	printf("方差为%f\n", S / (Length + 1));
	system("pause");
	Menu1();
}
void StdDev() //求标准差
{
	system("cls");
	float sum = 0, S = 0;
	for (i = 0; i < Length; i++)
		sum += Array[i];
	sum = sum / (Length + 1);
	for (i = 0; i < Length; i++)
		S += pow(Array[i] - sum, 2);
	S = S / (Length + 1);
	S = sqrt(S);
	printf("标准差为%f\n", S);
	system("pause");
	Menu1();
}
void Statistics() //统计
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 求最大值\n");
	printf("-2 求最小值\n");
	printf("-3 求平均值\n");
	printf("-4 求方差\n");
	printf("-5 求标准差\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		Max();
	case 2:
		Min();
	case 3:
		Average();
	case 4:
		Variance();
	case 5:
		StdDev();
	default:
		Statistics();
	}
}
void SeqSearch() //顺序查找
{
	system("cls");
	temp = 0;
	printf("请输入需要的查找的数\n");
	scanf("%d", &a);
	for (i = 0; i < Length; i++)
		if (Array[i] == a)
		{
			printf("Array[%d]=%d\n", i, a);
			temp++;
		}
	if (temp == 0)
		printf("没有这个数\n");
	system("pause");
	Menu1();
}
void BiSearch() //折半查找
{
	system("cls");
	int temp1 = 0, temp2 = 0;
	for (i = 0; i < Length - 1; i++)
	{
		if (Array[i] >= Array[i + 1])
			temp1++;
	}
	for (i = 0; i < Length - 1; i++)
	{
		if (Array[i] <= Array[i + 1])
			temp2++;
	}
	if (temp1 == Length - 1 || temp2 == Length - 1)
	{
		int left = 0, right = Length - 1, mid;
		printf("请输入一个数：\n");
		scanf("%d", &a);
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (Array[mid] == a)
			{
				if (Array[mid - 1] != Array[mid] && Array[mid + 1] != Array[mid])
					printf("Array[%d]=%d\n", mid, a);
				else
					for (i = left; i < right + 1; i++)
						if (Array[i] == a)
							printf("Array[%d]=%d\n", i, a);
				goto end;
			}
			else if (Array[mid] > a)
				right = mid - 1;
			else if (Array[mid] < a)
				left = mid + 1;
		}
		printf("无此数！\n");
	}
	else
	{
		printf("不是顺序数组!\n");
	}
end:
	system("pause");
	Menu1();
}
void Search() //查找
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 顺序查找\n");
	printf("-2 折半查找\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		SeqSearch();
	case 2:
		BiSearch();
	default:
		Search();
	}
}
void IsAsc() //是否升序排列
{
	system("cls");
	temp = 0;
	for (i = 0; i < Length - 1; i++)
		if (Array[i] > Array[i + 1])
			temp++;
	if (temp == 0)
		printf("升序排列\n");
	else
		printf("不是升序排列\n");
	system("pause");
	Menu1();
}
void IsDesc() //是否降序排列
{
	system("cls");
	temp = 0;
	for (i = 0; i < Length - 1; i++)
		if (Array[i] < Array[i + 1])
			temp++;
	if (temp == 0)
		printf("降序排列\n");
	else
		printf("不是降序排列\n");
	system("pause");
	Menu1();
}
void IsAllEqual() //是否全部元素相等
{
	system("cls");
	temp = 0;
	for (i = 0; i < Length - 1; i++)
		if (Array[i] != Array[i + 1])
			temp++;
	if (temp == 0)
		printf("全部元素相等\n");
	else
		printf("不是全部元素相等\n");
	system("pause");
	Menu1();
}
void Judge() //判断
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 是否升序排列\n");
	printf("-2 是否降序排列\n");
	printf("-3 是否全部元素相等\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		IsAsc();
	case 2:
		IsDesc();
	case 3:
		IsAllEqual();
	default:
		Judge();
	}
}
void upBubble() //升序冒泡法
{
	for (i = 0; i < Length; i++)
		for (j = 0; j < Length - 1; j++)
			if (Array[j] > Array[j + 1])
			{
				temp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
			}
	PrintArray();
}
void downBubble() //降序冒泡法
{
	for (i = 0; i < Length; i++)
		for (j = 0; j < Length - 1; j++)
			if (Array[j] < Array[j + 1])
			{
				temp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
			}
	PrintArray();
}
void BubbleSort() //冒泡法
{
	system("cls");
	printf("请选择升序排列或者降序排列\n");
	printf("-0 返回上级菜单\n");
	printf("-1 升序排列\n");
	printf("-2 降序排列\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Sort();
	case 1:
		upBubble();
	case 2:
		downBubble();
	default:
		BubbleSort();
	}
}
void upSelect() //升序选择法
{
	int min, linshi;
	jiuxing = Length;
	for (i = 0; i < jiuxing; i++)
	{
		linshi = 0;
		min = Array[i];
		a = i;
		for (j = i + 1; j < jiuxing; j++)
			if (min > Array[j])
			{
				a = j;
				linshi = 1;
				min = Array[j];
			}
		if (linshi == 1)
		{
			temp = Array[i];
			Array[i] = Array[a];
			Array[a] = temp;
		}
	}
	PrintArray();
}
void downSelect() //降序选择法
{
	int max, linshi;
	jiuxing = Length;
	for (i = 0; i < jiuxing; i++)
	{
		linshi = 0;
		max = Array[i];
		a = i;
		for (j = i + 1; j < jiuxing; j++)
			if (max < Array[j])
			{
				a = j;
				linshi = 1;
				max = Array[j];
			}
		if (linshi == 1)
		{
			temp = Array[i];
			Array[i] = Array[a];
			Array[a] = temp;
		}
	}
	PrintArray();
}
void SelectSort() //选择法
{
	system("cls");
	printf("请选择升序排列或者降序排列\n");
	printf("-0 返回上级菜单\n");
	printf("-1 升序排列\n");
	printf("-2 降序排列\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Sort();
	case 1:
		upSelect();
	case 2:
		downSelect();
	default:
		SelectSort();
	}
}
void upExchange() //升序交换法
{
	int min, linshi;
	jiuxing = Length;
	for (i = 0; i < jiuxing; i++)
	{
		linshi = 0;
		min = Array[i];
		a = i;
		for (j = i + 1; j < jiuxing; j++)
			if (min > Array[j])
			{
				a = j;
				linshi = 1;
				min = Array[j];
			}
		if (linshi == 1)
		{
			temp = Array[i];
			Array[i] = Array[a];
			for (j = a; j > i + 1; j--)
				Array[j] = Array[j - 1];
			Array[i + 1] = temp;
		}
	}
	PrintArray();
}
void downExchange() //降序交换法
{
	int max, linshi;
	jiuxing = Length;
	for (i = 0; i < jiuxing; i++)
	{
		linshi = 0;
		max = Array[i];
		a = i;
		for (j = i + 1; j < jiuxing; j++)
			if (max < Array[j])
			{
				a = j;
				linshi = 1;
				max = Array[j];
			}
		if (linshi == 1)
		{
			temp = Array[i];
			Array[i] = Array[a];
			for (j = a; j > i + 1; j--)
				Array[j] = Array[j - 1];
			Array[i + 1] = temp;
		}
	}
	PrintArray();
}
void ExchangeSort() //交换法
{
	system("cls");
	printf("请选择升序排列或者降序排列\n");
	printf("-0 返回上级菜单\n");
	printf("-1 升序排列\n");
	printf("-2 降序排列\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Sort();
	case 1:
		upExchange();
	case 2:
		downExchange();
	default:
		ExchangeSort();
	}
}
void Sort() //排序
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 冒泡法\n");
	printf("-2 选择法\n");
	printf("-3 交换法\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Arrange();
	case 1:
		BubbleSort();
	case 2:
		SelectSort();
	case 3:
		ExchangeSort();
	default:
		Sort();
	}
}
void Reverse() //逆置数组
{
	int tempArray[Length];
	for (i = 0; i < Length; i++)
		tempArray[i] = Array[Length - i - 1];
	for (i = 0; i < Length; i++)
		Array[i] = tempArray[i];
	PrintArray();
}
void RotateLeft() //左旋数组
{
	system("cls");
	printf("请输入从左边第几位开始左旋\n");
	scanf("%d", &a);
	int tempArray[Length];
	for (i = 0; i < Length - a + 1; i++)
		tempArray[i] = Array[a + i];
	for (i = Length - a; i < Length; i++)
		tempArray[i] = Array[i - Length + a];
	for (i = 0; i < Length; i++)
		Array[i] = tempArray[i];
	PrintArray();
}
void RotateRight() //右旋数组
{
	system("cls");
	printf("请输入从右边第几位开始右旋\n");
	scanf("%d", &temp);
	a = Length - temp;
	int tempArray[Length];
	for (i = 0; i < Length - a + 1; i++)
		tempArray[i] = Array[a + i];
	for (i = Length - a; i < Length; i++)
		tempArray[i] = Array[i - Length + a];
	for (i = 0; i < Length; i++)
		Array[i] = tempArray[i];
	PrintArray();
}
void Arrange() //排列数组元素
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 排序\n");
	printf("-2 逆置数组\n");
	printf("-3 左旋数组\n");
	printf("-4 右旋数组\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		Sort();
	case 2:
		Reverse();
	case 3:
		RotateLeft();
	case 4:
		RotateRight();
	default:
		Arrange();
	}
}
void Yuesefu() //约瑟夫环
{
	system("cls");
	jiuxing = 0;
	printf("请输入人数以及每几个人杀一个人：\n");
	int N, M, k;
	scanf("%d %d", &N, &M);
	int Yuesefu[N][2], count;
	for (i = 0; i < N; i++)
	{
		Yuesefu[i][0] = i + 1;
		Yuesefu[i][1] = -7;
	}
	for (i = 0, k = 1;; i++)
	{
		if ((k) % M == 0 && Yuesefu[i][1] != 0)
		{
			if (jiuxing % Num_row == 0)
				printf("\n");
			jiuxing++;
			printf("%6d ", Yuesefu[i][0]);
			Yuesefu[i][1] = 0;
		}
		if (i == N - 1)
			i = -1;
		if (Yuesefu[i + 1][1] != 0)
			k++;
		count = 0;
		for (j = 0; j < N; j++)
			if (Yuesefu[j][1] == 0)
				count++;
		if (N - count < M)
		{
			printf("\n幸存者：");
			for (i = 0; i < N; i++)
				if (Yuesefu[i][1] == -7)
					printf("%d ", Yuesefu[i][0]);
			break;
		}
	}
	printf("\n");
	system("pause");
	Menu1();
}
void Sushu() //筛法求素数
{
	system("cls");
	temp = 0;
	int max;
	printf("请输入需要求的数的最大范围：\n");
	scanf("%d", &max);
	int what[max];
	for (i = 0; i < max; i++)
		what[i] = i + 1;
	for (i = 1; i < max; i++)
	{
		if (what[i] != 0)
		{
			for (j = i + 1; j < max; j++)
			{
				if (what[j] % what[i] == 0)
					what[j] = 0;
			}
		}
	}
	int huanhang;
	huanhang = 0;
	for (i = 1; i < max; i++)
	{
		if (what[i] != 0)
		{
			printf("%6d", what[i]);
			huanhang++;
			if (huanhang % Num_row == 0)
				printf("\n");
		}
	}
	printf("\n");
	if (huanhang == 0)
		printf("没有素数！\n");
	system("pause");
	Menu1();
}
void Zixvan() //其他自选功能
{
	system("cls");
	printf("无其他自选功能！\n");
	system("pause");
	Menu1();
}
void Xvanzuo() //选做
{
	system("cls");
	printf("-0 返回上级菜单\n");
	printf("-1 约瑟夫环\n");
	printf("-2 筛法求素数\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		Menu1();
	case 1:
		Yuesefu();
	case 2:
		Sushu();
	default:
		Xvanzuo();
	}
}
void Menu1() //主菜单
{
	system("cls");
	printf("菜单\n");
	printf("- 0 退出程序\n");
	printf("- 1 配置参数\n");
	printf("- 2 生成样本数据\n");
	printf("- 3 显示数组\n");
	printf("- 4 删除\n");
	printf("- 5 插入\n");
	printf("- 6 统计\n");
	printf("- 7 查找\n");
	printf("- 8 判断\n");
	printf("- 9 排列数组元素\n");
	printf("-10 数组的其他应用\n");
	printf("-11 其他自选功能\n");
	scanf("%d", &a);
	switch (a)
	{
	case 0:
		exit(0);
	case 1:
		Config();
	case 2:
		FillArray();
	case 3:
		PrintArray();
	case 4:
		Delete();
	case 5:
		Insert();
	case 6:
		Statistics();
	case 7:
		Search();
	case 8:
		Judge();
	case 9:
		Arrange();
	case 10:
		Xvanzuo();
	case 11:
		Zixvan();
	default:
		Menu1();
	}
}
int main() //主函数
{
	Menu1();
	return 0;
}