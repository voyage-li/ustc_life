#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int big(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    char data[n][2][120];
    memset(data, 0, sizeof(data));
    for (int i = 0; i < n; i++)
    {
        scanf("%s", data[i][0]);
        scanf("%s", data[i][1]);
        getchar();
        getchar(); //avoid '\n'
    }
    for (int index = 0; index < n; index++)
    {
        char result[100];
        memset(result, 0, sizeof(result));
        int position1, position2, position;
        for (position1 = 0; data[index][0][position1] != '.'; position1++)
            ;
        for (position2 = 0; data[index][1][position2] != '.'; position2++)
            ;
        //dot location
        position = big(position1, position2) + 1;
        result[position] = '.';
        int i = 1, j = 1, k = 1, flag = 0;
        while (1)
        {
            result[position - k] = data[index][0][position1 - i] + data[index][1][position2 - j] - '0' - '0' + flag + '0';
            flag = (result[position - k] - '0') / 10;
            result[position - k] = (result[position - k] - '0') % 10 + '0';
            if (i == position1 && j == position2)
            {
                result[position - k - 1] = flag + '0';
                break;
            }
            if (i == position1) //when num1 to the end change the end of it to 0
            {
                data[index][0][position1 - i] = '0';
                i--;
            }
            if (j == position2) //when num2 to the end change the end of it to 0
            {
                data[index][1][position2 - j] = '0';
                j--;
            }
            i++;
            j++;
            k++;
        }

        int rear1, rear2, rear;
        for (rear1 = 0; data[index][0][rear1] != '\0'; rear1++)
            ;
        for (rear2 = 0; data[index][1][rear2] != '\0'; rear2++)
            ;
        rear = position + big(rear1 - position1, rear2 - position2);
        result[rear] = '\0';
        i = 1;
        j = 1;
        k = 1;
        flag = 0;
        while (1)
        {
            if (data[index][0][rear - i - position + position1] == '\0' || data[index][1][rear - j - position + position2] == '\0')
                result[rear - k] = data[index][0][rear - i - position + position1] + data[index][1][rear - j - position + position2] + flag;
            else
                result[rear - k] = data[index][0][rear - i - position + position1] + data[index][1][rear - j - position + position2] + flag - '0';
            flag = (result[rear - k] - '0') / 10;
            result[rear - k] = (result[rear - k] - '0') % 10 + '0';
            i++;
            j++;
            k++;
            if (data[index][0][rear - i - position + position1] == '.' && data[index][1][rear - j - position + position2] == '.')
                break;
        }

        i = 1;
        while (flag != 0) //from number behind dot
        {
            result[position - i] = result[position - i] + flag;
            flag = (result[position - i] - '0') / 10;
            result[position - i] = (result[position - i] - '0') % 10 + '0';
            i++;
        }

        //avoid 0 behind
        i = 0;
        while (result[i] == '\0' || result[i] == '0')
            i++;
        while (result[i] != '\0')
            i++;
        i--;
        while (result[i] == '0')
            result[i--] = '\0';

        i = 0;
        while (result[i] == '\0' || result[i] == '0')
            i++;
        if (result[i] == '.')
            putchar('0');
        while (result[i] != '\0')
        {
            printf("%c", result[i++]);
        }
        printf("\n");
    }
}

int big(int a, int b)
{
    return a > b ? a : b;
}