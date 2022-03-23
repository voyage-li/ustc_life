#include <stdio.h>
#include <math.h>
#include <string.h>

/* 
    使用dfs
    每一次进入函数先循环竖着切，留左边与留右边分别进入下一次函数
    再循环横着切，留上边和留下边进入下一层函数
 */

double min = 999999; //sigema xi^2 的最小值

void chessboard(int score[], int l, int w, double answer[], int n, int now, double sum)
{
    if (now > 0)
        sum += answer[now-1] * answer[now-1];//计算当前已分出来的块的分数平方的和
    if (sum > min)//如果当前的已经比最小的大了，直接返回
        return;
    if (now + 1 == n)//已经分出来了n-1块，最后一块就可以及直接计算，并比较答案了
    {
        for (int i = 0; i < w; i++)
            for (int j = 0; j < l; j++)
                answer[now] += score[l * i + j];
        sum += answer[now] * answer[now];
        if (sum < min)
            min = sum;
        answer[now] = 0; //状态返回
        return;
    }
    for (int i = 0; i < l - 1; i++)
    {
        //竖着切留左边
        for (int m = 0; m <= i; m++)
            for (int t = 0; t < w; t++)
                answer[now] += score[l * t + m];
        int temp1[w][l - i - 1];
        for (int m = 0; m < w; m++)
            for (int t = 0; t < l - i - 1; t++)
                temp1[m][t] = score[m * l + t + i + 1];
        chessboard(*temp1, l - i - 1, w, answer, n, now + 1, sum);
        answer[now] = 0;

        //竖着切留右边
        for (int m = i + 1; m < l; m++)
            for (int t = 0; t < w; t++)
                answer[now] += score[l * t + m];
        int temp2[w][i + 1];
        for (int m = 0; m < w; m++)
            for (int t = 0; t < i + 1; t++)
                temp2[m][t] = score[m * l + t];
        chessboard(*temp2, i + 1, w, answer, n, now + 1, sum);
        answer[now] = 0;
    }
    for (int i = 0; i < w - 1; i++)
    {
        //横着切留上边
        for (int m = 0; m < l; m++)
            for (int t = 0; t <= i; t++)
                answer[now] += score[l * t + m];
        int temp1[w - i - 1][l];
        for (int m = 0; m < w - i - 1; m++)
            for (int t = 0; t < l; t++)
                temp1[m][t] = score[(m + i + 1) * l + t];
        chessboard(*temp1, l, w - i - 1, answer, n, now + 1, sum);
        answer[now] = 0;

        //横着切留下边
        for (int m = 0; m < l; m++)
            for (int t = i + 1; t < w; t++)
                answer[now] += score[l * t + m];
        int temp2[i + 1][l];
        for (int m = 0; m < i + 1; m++)
            for (int t = 0; t < l; t++)
                temp2[m][t] = score[m * l + t];
        chessboard(*temp2, l, i + 1, answer, n, now + 1, sum);
        answer[now] = 0;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int score[8][8];
    double answer[n]; //记录每一次临时分割情况下每一个小块的分数
    memset(answer, 0, sizeof(answer));
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            scanf("%d", &score[i][j]);

    chessboard(*score, 8, 8, answer, n, 0, 0);
    double sum = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            sum += score[i][j];
    sum = sqrt((n * min - sum * sum) / (n * n));

    //四舍五入取三位小数
    double a = (int)sum * 1000;
    if (1000 * sum - a >= 0.5)
        a = (a + 1) / 1000;
    else
        a = a / 1000;
    printf("%.3f", sum);

    return 0;
}