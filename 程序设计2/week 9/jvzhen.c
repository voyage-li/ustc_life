#include <stdio.h>
#include <string.h>

int maxanswer = 0;
int temp[100];

int max(int a, int b);
void fun(int p[], int n);

int main()
{
    int n;
    scanf("%d", &n);
    int data[n][n];
    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            while ((c = getchar()) == '\n' || c == ' ') //过滤空格和换行
                ;
            ungetc(c, stdin); //将读入的数据退回输入流
            scanf("%d", &data[i][j]);
        }

    //分别计算取1行，2行到n行时的最大值
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            memset(temp, 0, sizeof(temp));
            for (int k = 0; k < n; k++)
                for (int p = i; p <= j; p++)
                    temp[k] += data[p][k];
            fun(temp, n);
        }

    printf("%d\n", maxanswer);
    return 0;
}
void fun(int p[], int n)
/* 
    状态：dp[i]表示以第i个元素为结尾的最大连续序列的和
    状态转移：要么是前一个最大的加上当前对应的数，要么就是当前的数
 */
{
    int dp[n];
    dp[0] = p[0];
    maxanswer=max(maxanswer,dp[0]);
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(p[i], dp[i - 1] + p[i]);
        maxanswer = max(maxanswer, dp[i]);
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}