#include <stdio.h>
#include <string.h>

//use strstr() to judge

int main()
{
    int index = 0, i, j;
    char string[1000][30];
    while ((scanf("%s", string[index++])) > 0)
        ;
    int total_number = index - 1;
    char answer[total_number][30];
    char temp[30];
    int record = 0;
    for (i = 0; i < total_number; i++)
    {
        memset(temp, 0, sizeof(temp));
        index = 1;
        while (1)
        {
            if (string[i][index] == '\0') //the end of the array
            {
                strcpy(answer[i], string[i]);
                break;
            }
            if (index == 2)
            {
                for (j = 0; j < index; j++)
                    temp[j] = string[i][j];
                temp[index] = '\0';
            }
            else // it only need to assign once most conditions
            {
                temp[index - 1] = string[i][index - 1];
                temp[index] = '\0';
            }
            for (j = 0; j < i; j++) //judge front
            {
                if (strstr(string[j], temp) == string[j])
                //strstr() point to the begin of the string means it will not the answer
                {
                    record = -1; //jump out of circle
                    break;
                }
            }
            if (record == 0)
            {
                for (j = i + 1; j < total_number; j++)
                    if (strstr(string[j], temp) == string[j])
                    //strstr() point to the begin of the string means it will not the answer
                    {
                        record = -1;
                        break;
                    }
            }
            else
            {
                index++;
                record = 0;
                continue;
            }
            if (record == -1)
            {
                index++;
                record = 0;
            }
            else
            {
                strcpy(answer[i], temp);
                record = 0;
                break;
            }
        }
    }
    for (i = 0; i < total_number; i++)
        printf("%s %s\n", string[i], answer[i]);
    return 0;
}