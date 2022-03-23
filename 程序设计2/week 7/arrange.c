#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
    使用递归的方法，求n个元素的全排列即为求n-1个元素的全排列，再将每一个元素分别交换到第一位
 */
void arrange(int num[], int length, int answer[][10], int *p, int now)
{
    if (now == length)
    //已经递归到只有一个元素排列
    {
        for (int i = 0; i < length; i++)
            answer[*p][i] = num[i];
        (*p)++;
    }
    else
    {
        for (int i = now; i < length; i++)
        {
            int swap;
            swap = num[i];
            num[i] = num[now];
            num[now] = swap;
            //交换元素
            arrange(num, length, answer, p, now + 1);
            swap = num[i];
            num[i] = num[now];
            num[now] = swap;
            //恢复交换
        }
    }
}

int compare(int num[], int a, int b) //根据输入判断数字先后顺序
{
    int i = 0, j = 0;
    while (num[i] != a)
        i++;
    while (num[j] != b)
        j++;
    if (i < j)
        return 1; //顺序返回1
    else if (i == j)
        return 0;
    else //逆序返回-1
        return -1;
}

//对排列好的元素进行排列
void dictionary(int answer[][10], int length, int num[], int total)
{
    int temp = 0;
    for (int i = 0; i < total; i++)
        for (int j = i + 1; j < total; j++)
        {
            for (int k = 0; k < length; k++)
            {
                int tmp = compare(num, answer[i][k], answer[j][k]);
                if (tmp == 1) //顺序则直接进行下一次比较
                {
                    temp = 0;
                    break;
                }
                else if (tmp == -1) //逆序则直接交换
                {
                    temp = 1;
                    break;
                }
                //相同则比较下一个数字
            }
            if (temp == 1)
                for (int m = 0; m < length; m++)
                {
                    temp = answer[i][m];
                    answer[i][m] = answer[j][m];
                    answer[j][m] = temp;
                }
            temp = 0;
        }
}

int main()
{
    int number[10];
    int index = 0;
    while ((scanf("%d", &number[index])) > 0)
        index++;
    int a = 1;
    for (int i = 1; i <= index; i++)
        a *= i;
    int answer[a][10];
    memset(answer, 0, sizeof(answer));
    int *p = (int *)malloc(sizeof(int));
    *p = 0;

    arrange(number, index, answer, p, 0);

    dictionary(answer, index, number, a);

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < index; j++)
            printf("%d", answer[i][j]);
        printf("\n");
    }
    free(p);
    return 0;
}