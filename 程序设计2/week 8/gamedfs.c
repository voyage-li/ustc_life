#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* 
	第一次使用bfs写，一直无法过第四个测试点，主要原因应该时情况太多，数组会溢出，减少储存的数据数量非常复杂
	所以采用dfs尽管不能一次得到最少的答案，但是可以避免很多不必要的存储
 */

int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; //不同的移动
int steps_min = 9999;

void search(char card[][80], int went[][80], int x1, int y1, int x2, int y2, int length, int width, int steps_now, int last)
//原始数据 状态函数 初始点(x,y) 目的点(x,y) 原始数据的长 原始数据的宽 步数 上次移动的方向
{
	if (steps_now > steps_min) //如果此时的步数已经超过了最小步数，再搜索下去已经没有意义了
		return;
	if (x1 == x2 && y1 == y2) //记录本次搜索的结果
	{
		if (steps_now < steps_min)
			steps_min = steps_now;
		return;
	}
	went[x1][y1] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x = x1 + move[i][0];
		int y = y1 + move[i][1];
		if (x >= 0 && x <= length + 1 && y >= 0 && y <= width + 1)
		{
			if (went[x][y] == 1)
				continue;
			if (card[x][y] == ' ')
			{
				if (last != i) //如果移动和上次相同，steps不增加
					search(card, went, x, y, x2, y2, length, width, steps_now + 1, i);
				else
					search(card, went, x, y, x2, y2, length, width, steps_now, i);
				went[x][y] = 0; //状态返回
			}
		}
	}
}

int main()
{
	int length, width;
	int index = 1; //用来记录不同的card
	int card_a[2], card_b[2];
	char card[80][80];
	int went[80][80];

	while (1)
	{
		scanf("%d %d", &length, &width);

		if (length == 0 && width == 0)
			break;
		for (int i = 0; i < 80; i++)
			for (int j = 0; j < 80; j++)
				card[i][j] = ' ';

		for (int i = 1; i < width + 1; i++)
		{
			//录入数据从1开始录入，给线路走出矩形板留下空间
			getchar(); //avoid '\n'
			for (int j = 1; j < length + 1; j++)
				scanf("%c", &card[j][i]);
		}

		printf("Board #%d:\n", index);

		int temp = 1; //用来记录当前判断的是该card下的第几种数据
		while (1)
		{
			scanf("%d %d %d %d", &card_a[0], &card_a[1], &card_b[0], &card_b[1]);
			if (card_a[0] == 0 && card_a[1] == 0 && card_b[0] == 0 && card_b[1] == 0) //判断本次输入是否结束
				break;

			steps_min = 9999;
			card[card_b[0]][card_b[1]] = ' '; //将目标点的值改变为空，方便搜索
			memset(went, 0, sizeof(went));	  //每次进入函数前确保状态函数归零

			search(card, went, card_a[0], card_a[1], card_b[0], card_b[1], length, width, 0, -1);

			if (steps_min != 9999)
				printf("Pair %d: %d segments.\n", temp, steps_min);
			else
				printf("Pair %d: impossible.\n", temp);
			card[card_b[0]][card_b[1]] = 'X'; //复原改变的值
			temp++;
		}

		printf("\n");
		index++;
	}
	return 0;
}