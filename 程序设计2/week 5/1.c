#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
    use the thoughts of divide and conquer to caculate pow(x,n)
    if x%2==0 return pow(x*x,n/2)
    if x%2==1 return x*pow(x*x,(n-1)/2)
*/

int *Multiply(int num1[], int num2[], int n, int n_start);

int main()
{
    int n;
    scanf("%d", &n);

    int begin[2] = {2, -1};
    //use -1 to record the length of array
    int *result;

    result = Multiply(begin, begin, n, n);

    int rear;
    for (int index = 0;; index++)
        if (*(result + index) == -1)
        {
            rear = index - 1;
            break;
        }
    //to find the length of the answer

    for (; rear >= 0; rear--)
        printf("%d", *(result + rear));
    // the result need to be reversed
    free(result);
    return 0;
}

int *Multiply(int num1[], int num2[], int n, int n_start)
{
    if (n == 1)
        return num1;
    // return condition

    int length1, length2;
    for (length1 = 0; num1[length1] != -1; length1++)
        ;
    for (length2 = 0; num2[length2] != -1; length2++)
        ;

    int *result = (int *)malloc(sizeof(int) * (length2 + length2 + 1));
    memset(result, 0, sizeof(int) * (length1 + length2 + 1));

    for (int i = 0; i < length1; i++)
        for (int j = 0; j < length2; j++)
            result[i + j] += num1[i] * num2[j];

    for (int index = 0; index < length2 + length1; index++)
    {
        result[index + 1] += result[index] / 10;
        result[index] %= 10;
    }

    if (n != n_start) //n_start is used to avoid free {2,-1}
    {
        if (num1[0] != 2 && num1[1] != -1 && n % 2 == 0)
            free(num1);
        /* free RAM used by malloc
        do not free the array contained {2,-1} it was not creat by malloc,
        do not free if it will be use again */
    }

    if (result[length1 + length2 - 1] == 0)
        result[length1 + length2 - 1] = -1;
    else
        result[length1 + length2] = -1;

    // recursion
    if (n % 2 == 0)
        return Multiply(result, result, n / 2, n_start);
    else
        return Multiply(num1, Multiply(result, result, (n - 1) / 2, n_start), 2, n_start);
}

//maybe some RAMs were not free