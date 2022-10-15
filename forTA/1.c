#include <stdio.h>
int data[9] = {0};
int fre[10] = {0};
int find(int loc)
{
    if (loc == 9)
    {
        if ((10 * data[0] + data[1]) * (100 * data[2] + 10 * data[3] + data[4]) == 1000 * data[5] + 100 * data[6] + 10 * data[7] + data[8])
        {
            printf("%d%d * %d%d%d == %d%d%d%d\n", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8]);
            return 1;
        }
        return 0;
    }
    int temp = 0;
    for (data[loc] = 0; data[loc] <= 9; data[loc]++)
    {
        if (data[loc] == 0 && (loc == 0 || loc == 2 || loc == 5))
            continue;
        else if (fre[data[loc]] == 1)
            continue;
        fre[data[loc]] = 1;
        temp += find(loc + 1);
        fre[data[loc]] = 0;
    }
    return temp;
}

int main()
{
    printf("%d\n", find(0));
    return 0;
}