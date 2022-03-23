#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool judge(double num[], int length);
// the most important is,we should use fabs() not abs()
int main()
{
    double num[4];
    while (1)
    {
        scanf("%lf %lf %lf %lf", &num[0], &num[1], &num[2], &num[3]);
        if (abs(num[0]) <= 1e-9 && fabs(num[1]) <= 1e-9 && abs(num[2]) <= 1e-9 && fabs(num[3]) <= 1e-9)
            //the end of the while
            break;
        if (judge(num, 4))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
bool judge(double num[], int length)
{
    /* 
        when we are solving how to make 24 with 4 numbers ,we can select two of them ,use + - * / to calculate selected numbers,
        then the problem changed to how to make 24 with 3 numbers
     */

    if (length == 1 && fabs(num[0] - 24) <= 1e-9)
        //the last number in the array must be 24,or it is not the answer
        return true;
    else
    {
        double s[length - 1];
        for (int i = 0; i < length; i++)
            for (int j = 0; j < length; j++)
                if (i != j && num[i] <= num[j]) //decrease the circle
                {
                    int index1 = 0, index2 = 0;
                    while (1)
                    {
                        if (index2 != i && index2 != j)
                            s[index1++] = num[index2];
                        index2++;
                        if (index2 == length)
                            break;
                    } //form the new array,do not add the same number into the array,or do not add numbers we have already selected.

                    s[index1] = num[i] + num[j];
                    if (judge(s, length - 1))
                        return true;

                    s[index1] = num[i] * num[j];
                    if (judge(s, length - 1))
                        return true;

                    s[index1] = num[i] - num[j]; //remember that a-b!=b-a
                    if (judge(s, length - 1))
                        return true;

                    s[index1] = -num[i] + num[j];
                    if (judge(s, length - 1))
                        return true;

                    if (num[j] != 0)
                    //avoid 0,it is important
                    {
                        s[index1] = num[i] / num[j];
                        if (judge(s, length - 1))
                            return true;
                    }
                    if (num[i] != 0)
                    {
                        s[index1] = num[j] / num[i];
                        if (judge(s, length - 1))
                            return true;
                    }
                }
    }
    return false;
    //after all the circle ,we still not find the answer
}