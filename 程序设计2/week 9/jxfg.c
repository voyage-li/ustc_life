#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
    借鉴了网上的思路
    一组数据有十五个点，用一个二进制的数来表示这些的点的占用情况
    然后递归每两个点构造出的矩形，找到每一种占用后最小的占用方法
 */

int num;          //测试数据组数
int min[1 << 15]; //不同占用下的面积
int data[15][2];  //原始数据

int area(int i, int j) //计算两个点之间矩形的面积
{
    if (data[i][0] == data[j][0])
        return abs(data[i][1] - data[j][1]);
    if (data[i][1] == data[j][1])
        return abs(data[i][0] - data[j][0]);
    return abs(data[i][1] - data[j][1]) * abs(data[i][0] - data[j][0]);
}
int search(int n)
{
    int i, j, k;
    if (min[n] >= 0) //已经计算过，剪枝
        return min[n];
    if (n == 0) //全部占用，返回
        return min[n] = 0;
    min[n] = 2000 * 2000;             //整个测试区间
    for (i = 0; i < num; i++)         //遍历每一个点
        if (n & (1 << i))             //当前的点还没有计算
            for (j = 0; j < num; j++) //遍历除选择点以外的其他点
                if (i != j)
                {
                    int temp, s;
                    temp = n & (~((1 << i) | (1 << j))); //将选择的两个点设为已经考虑过
                    for (k = 0; k < num; k++)            //剔除占用的矩形上的点
                        if ((data[i][0] == data[k][0] && data[j][1] == data[k][1]) ||
                            (data[i][1] == data[k][1] && data[j][0] == data[k][0]))
                            temp &= (~(1 << k));
                    s = area(i, j) + search(temp); //该种情况下最小面积
                    if (s < min[n])
                        min[n] = s;
                }
    return min[n];
}

int main()
{
    int temp;
    scanf("%d", &num);
    while (num != 0)
    {
        temp = (1 << num) - 1;
        for (int i = 0; i < num; i++)
            scanf("%d %d", &data[i][0], &data[i][1]);
        memset(min, -1, sizeof(min));
        printf("%d\n", search(temp));
        scanf("%d", &num);
    }
    return 0;
}