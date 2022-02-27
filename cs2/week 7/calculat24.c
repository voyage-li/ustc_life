#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

double reckon(char s, double num1, double num2);

double function1(char s[], double num[]); //5 different calculate methods
double function2(char s[], double num[]);
double function3(char s[], double num[]);
double function4(char s[], double num[]);
double function5(char s[], double num[]);

bool judge(double number[][4]) //judge the answer
{
    char s[4] = {'+', '-', '*', '/'};
    char temp[4];
    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 4; b++)
            for (int c = 0; c < 4; c++)
            {
                temp[0] = s[a];
                temp[1] = s[b];
                temp[2] = s[c];
                if ((a == b && b == c) && (a == 0 || a == 2))
                {
                    if (fabs(function1(temp, number[0]) - 24) < 1e-9)
                        return true;
                }
                for (int i = 0; i < 24; i++)
                {
                    if (fabs(function1(temp, number[i]) - 24) <= 1e-9)
                        return true;
                    if (fabs(function2(temp, number[i]) - 24) <= 1e-9)
                        return true;
                    if (fabs(function3(temp, number[i]) - 24) <= 1e-9)
                        return true;
                    if (fabs(function4(temp, number[i]) - 24) <= 1e-9)
                        return true;
                    if (fabs(function5(temp, number[i]) - 24) <= 1e-9)
                        return true;
                    if ((a == b && b == c) && (a == 0 || a == 2))
                        break;
                }
            }
    return false;
}

void arrange(double num[], double arrange_number[][4], int add, int *number) //find all the arrangements of num
{
    if (add == 3)
    {
        for (int i = 0; i < 4; i++)
            arrange_number[*number][i] = num[i];
        (*number)++;
    }
    else
    {
        for (int i = add; i < 4; i++)
        {
            int swap;
            swap = num[i];
            num[i] = num[add];
            num[add] = swap;
            arrange(num, arrange_number, add + 1, number);
            swap = num[i];
            num[i] = num[add];
            num[add] = swap;
        }
    }
}

int main()
{

    int *number = (int *)malloc(sizeof(int));

    *number = 0; //the begin of the program
    double num[4];
    double arrange_number[24][4];
    while (1)
    {
        scanf("%lf %lf %lf %lf", &num[0], &num[1], &num[2], &num[3]);
        if (fabs(num[0]) <= 1e-9 && fabs(num[1]) <= 1e-9 && fabs(num[2]) <= 1e-9 && fabs(num[3]) <= 1e-9)
            break;

        arrange(num, arrange_number, 0, number);

        *number = 0; //do not forget to turn back it to 0,I spend most of my time finding this bug

        if (judge(arrange_number))
            printf("YES\n");
        else
            printf("NO\n");
    }
    free(number);
    return 0;
}

double reckon(char s, double num1, double num2)
{
    switch (s)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '/':
    {
        if (num2 == 0)
            return -100;
        return num1 / num2;
    }
    case '*':
        return num1 * num2;
    }
    return -1;
}

/*  ((AoB)oC)oD
    (Ao(BoC))oD
    Ao(Bo(CoD))
    Ao((BoC)oD)
    (AoB)o(CoD) */

double function1(char s[], double num[])
{
    double result;
    result = reckon(s[2], (reckon(s[1], reckon(s[0], num[0], num[1]), num[2])), num[3]);
    return result;
}

double function2(char s[], double num[])
{
    double result;
    result = reckon(s[2], (reckon(s[1], num[0], reckon(s[0], num[1], num[2]))), num[3]);
    return result;
}

double function3(char s[], double num[])
{
    double result;
    result = reckon(s[2], num[0], (reckon(s[1], num[1], reckon(s[0], num[2], num[3]))));
    return result;
}

double function4(char s[], double num[])
{
    double result;
    result = reckon(s[2], num[0], (reckon(s[1], reckon(s[0], num[1], num[2]), num[3])));
    return result;
}

double function5(char s[], double num[])
{
    double result;
    result = reckon(s[2], reckon(s[0], num[0], num[1]), reckon(s[1], num[2], num[3]));
    return result;
}
