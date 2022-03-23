#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char card[][80], int x1, int y1, int x2, int y2, int length, int width, int number)
//原始数据 初始点(x,y) 目的点(x,y) 原始数据的长 原始数据的宽
{
    card[x2][y2] = ' '; //改变目标点的值，方便查找

    int shed[999][2]; //储存当前移动到达的点
    memset(shed, 0, sizeof(shed));

    shed[0][0] = x1;
    shed[0][1] = y1;

    int steps[999]; //储存当前移动经过的线段数目
    int went[80][80];

    memset(steps, 0, sizeof(steps));
    memset(went, 0, sizeof(went));

    int now = 0, tail = 0;

    while (1)
    {
        if (went[shed[now][0]][shed[now][1]] == 1)
        {
            now++;
            continue;
        }
        if (shed[now][0] == x2 && shed[now][1] == y2) //由于使用的是广度优先搜索，找到的答案即为最小值
        {
            printf("Pair %d: %d segments.\n", number, steps[now]);
            return;
        }
        if (tail < now) //如果栈的尾指针比当前的指针还要小，说明该情况下无解
        {
            printf("Pair %d: impossible.\n", number);
            return;
        }
        //注意在判断card的原始数据时，应该先判断位置，防止越界
        //如果本次移动与上次移动时相同，则总线段数不变
        //如果移动和上次相反，直接跳过，减少空间时间浪费
        //其他情况下，本次移动会让总线段数加一
        //值得注意的是同一个方向是前进不同格的优先级是一样的
        if (shed[now][0] - 1 >= 0 && card[shed[now][0] - 1][shed[now][1]] == ' ')
        {
            tail++;
            shed[tail][0] = shed[now][0] - 1;
            shed[tail][1] = shed[now][1];
            steps[tail] = steps[now] + 1;
            int temp = tail;
            while (1)
            //值得注意的是同一个方向是前进不同格的优先级是一样的
            {
                if (shed[temp][0] - 1 >= 0 && card[shed[temp][0] - 1][shed[temp][1]] == ' ')
                {
                    tail++;
                    shed[tail][0] = shed[temp][0] - 1;
                    shed[tail][1] = shed[temp][1];
                    steps[tail] = steps[temp];
                    temp++;
                }
                else
                    break;
            }
        }
        if (shed[now][0] + 1 <= length + 1 && card[shed[now][0] + 1][shed[now][1]] == ' ')
        {
            tail++;
            shed[tail][0] = shed[now][0] + 1;
            shed[tail][1] = shed[now][1];
            steps[tail] = steps[now] + 1;
            int temp = tail;
            while (1)
            {
                if (shed[temp][0] + 1 <= length + 1 && card[shed[temp][0] + 1][shed[temp][1]] == ' ')
                {
                    tail++;
                    shed[tail][0] = shed[temp][0] + 1;
                    shed[tail][1] = shed[temp][1];
                    steps[tail] = steps[temp];
                    temp++;
                }
                else
                    break;
            }
        }
        if (shed[now][1] - 1 >= 0 && card[shed[now][0]][shed[now][1] - 1] == ' ')
        {
            tail++;
            shed[tail][0] = shed[now][0];
            shed[tail][1] = shed[now][1] - 1;
            steps[tail] = steps[now] + 1;
            int temp = tail;
            while (1)
            {
                if (shed[temp][1] - 1 >= 0 && card[shed[temp][0]][shed[temp][1] - 1] == ' ')
                {
                    tail++;
                    shed[tail][0] = shed[temp][0];
                    shed[tail][1] = shed[temp][1] - 1;
                    steps[tail] = steps[temp];
                    temp++;
                }
                else
                    break;
            }
        }
        if (shed[now][1] + 1 <= width + 1 && card[shed[now][0]][shed[now][1] + 1] == ' ')
        {
            tail++;
            shed[tail][0] = shed[now][0];
            shed[tail][1] = shed[now][1] + 1;
            steps[tail] = steps[now] + 1;
            int temp = tail;
            while (1)
            {
                if (shed[temp][1] + 1 <= width + 1 && card[shed[temp][0]][shed[temp][1] + 1] == ' ')
                {
                    tail++;
                    shed[tail][0] = shed[temp][0];
                    shed[tail][1] = shed[temp][1] + 1;
                    steps[tail] = steps[temp];
                    temp++;
                }
                else
                    break;
            }
        }
        went[shed[now][0]][shed[now][1]] = 1;
        now++;
    }
}

int main()
{
    int length, width;
    int index = 1; //用来记录不同的card
    int card_a[2], card_b[2];
    char card[80][80];

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
            search(card, card_a[0], card_a[1], card_b[0], card_b[1], length, width, temp);
            card[card_b[0]][card_b[1]] = 'X'; //将函数中改变的原始数据还原
            temp++;
        }
        printf("\n");
        index++;
    }
    return 0;
}