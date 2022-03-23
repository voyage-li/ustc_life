#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Mypowerbegin(char number[], int address_dot, int d);
int *Mypower(int result_last[], int _result_last[], int d, int address_dot, int number[]);

/* 
    use the thoughts of divide and conquer to caculate pow(x,n)
    if x%2==0 return pow(x*x,n/2)
    if x%2==1 return x*pow(x*x,(n-1)/2)
    use array to record data
    
    the question is:
        use too much malloc,but could not free RAM
        (it will be error if you try to free them,maybe the address of the pointer changes so that you can not free it)
        1<=n<=10, divide and conquer could not decrease the program execution time
 
*/

int main()
{
    char *number = (char *)malloc(sizeof(char) * 7);
    int d, index;
    int address_dot = 0;
    //record dot

    while (scanf("%s %2d", number, &d) == 2)
    {
        char *p;
        p = number;
        while (*p == '0')
            p++;
        //to avoid 0 ahead

        int length = strlen(p);
        for (index = length - 1; *(p + index) != '.'; index--)
        {
            if (*(p + index) == '0')
            {
                *(p + index) = '\0';
                if (*(p + index - 1) != '0')
                    break;
            }
            else
                break;
        }
        //to avoid 0 behind

        for (index = 0; *(p + index) != '\0'; index++)
        {
            if (*(p + index) == '.')
                address_dot = index;
        }
        //to record dot loction

        for (index = address_dot; *(p + index) != '\0'; index++)
            *(p + index) = *(p + index + 1);
        *(p + index - 1) = '\0';
        address_dot = strlen(p) - address_dot; //the number of dot

        Mypowerbegin(p, address_dot, d);

        getchar();
        //avoid '\n'
    }
    free(number);
    return 0;
}

void Mypowerbegin(char number[], int address_dot, int d)
{
    int index;
    int length = strlen(number);
    int *number_int = (int *)malloc(sizeof(int) * 50);

    for (index = 0; index < length; index++)
        number_int[index] = *(number + length - 1 - index) - '0';
    //reverse number and change it form char to int

    number_int[length] = -1;
    //to record the length of array

    address_dot = address_dot * d; // the location of answer dot

    int *ant = (int *)malloc(sizeof(int) * 50);
    ant = Mypower(number_int, number_int, d, address_dot, number_int);
    int temp;
    for (temp = 0; ant[temp] != -1; temp++)
        ;
    int answer[temp];
    for (int i = 0; i < temp; i++)
        answer[i] = ant[i];
    //if you operate with the return array ,it may go wrong!!!

    if (address_dot == 0)
    {
        for (index = temp - 1; index >= 0; index--)
            printf("%d", answer[index]);
        putchar('\n');
    }
    else if (temp > address_dot && address_dot != 0)
    {
        for (index = temp - 1; index > address_dot - 1; index--)
            printf("%d", answer[index]);
        putchar('.');
        while (index >= 0)
            printf("%d", answer[index--]);
        putchar('\n');
    }
    else
    {
        putchar('.');
        for (index = address_dot - temp; index > 0; index--)
            putchar('0');
        for (index = temp - 1; index >= 0; index--)
            printf("%d", answer[index]);
        putchar('\n');
    }
}

int *Mypower(int result_last[], int _result_last[], int d, int address_dot, int number[])
{
    if (d != 1)
    // return condition
    {
        int i, j;
        int length1;
        for (length1 = 0; result_last[length1] != -1; length1++)
            ;
        int length2;
        for (length2 = 0; _result_last[length2] != -1; length2++)
            ;
        int result_temp[length1];
        for (i = 0; i < length1; i++)
            result_temp[i] = result_last[i];
        int result[60];
        //if you operate with the return array ,it may go wrong!!!

        memset(result, 0, sizeof(result));

        for (i = 0; i < length2; i++)
            for (j = 0; j < length1; j++)
                result[i + j] += result_temp[j] * _result_last[i];
        for (i = 0; i < length1 + length2 - 1; i++)
        {
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
        //multiply

        (result[length1 + length2 - 1] == 0) ? (result[length1 + length2 - 1] = -1) : (result[length1 + length2] = -1);
        //record the length of array

        if (d % 2 == 0)
            return Mypower(result, result, d / 2, address_dot, number);
        else
            return Mypower(Mypower(result, result, (d - 1) / 2, address_dot, number), result_last, 2, address_dot, number);
        /* 
            recursion
            if x%2==0 return pow(x*x,n/2)
            if x%2==1 return x*pow(x*x,(n-1)/2)   
         */
    }
    else
        return result_last;
}