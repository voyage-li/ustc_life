#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[13][3] = {
    {'A', '\0'},
    {'2', '\0'},
    {'3', '\0'},
    {'4', '\0'},
    {'5', '\0'},
    {'6', '\0'},
    {'7', '\0'},
    {'8', '\0'},
    {'9', '\0'},
    {'1', '0', '\0'},
    {'J', '\0'},
    {'Q', '\0'},
    {'K', '\0'}};

int main()
{
    int card[52];
    while (1)
    {
        printf("========菜单=========\n");
        printf("|0. 退出程序        |\n");
        printf("|1. 发牌            |\n");
        printf("=====================\n");
        int select = 0;
        scanf("%d", &select);
        if (select == 0)
            exit(0);
        else
        {
            int already[52][2];
            memset(already, 0, sizeof(already));
            for (int i = 0; i < 52; i++)
            {
                already[i][0] = i;
            }
            int i = 0;
            while (i < 52)
            {
                int temp = rand() % 52;
                if (already[temp][1] == 1)
                    continue;
                else
                {
                    card[i++] = already[temp][0];
                    already[temp][1] = 1;
                }
            }
            for (int i = 0; i < 52; i++)
            {
                if (i % 13 == 0)
                    printf("\n");
                if (card[i] / 13 == 0)
                    printf("♠%s ", data[card[i] % 13]);
                else if (card[i] / 13 == 1)
                    printf("♥%s ", data[card[i] % 13]);
                else if (card[i] / 13 == 2)
                    printf("♣%s ", data[card[i] % 13]);
                else if (card[i] / 13 == 3)
                    printf("♦%s ", data[card[i] % 13]);
            }
            printf("\n\n");
        }
    }
}