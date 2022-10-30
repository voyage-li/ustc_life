#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[20] = {0};
    int num, tmp;
    int mid, low, high;
    srand((unsigned)time(NULL));
    // insert_sort
    for (int i = 0; i < 20; i++)
    {
        num = rand() % 101;
        a[i] = num;
        for (int j = 0; j < i; j++)
        {
            if (a[j] > num)
            {
                //后移
                for (int k = i; k > j; k--)
                    a[k] = a[k - 1];
                a[j] = num;
                break;
            }
        }
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%-5d ", a[i]);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
    for (int i = 0; i < 3; i++)
    {
        printf("\n输入你要找的数据：");
        scanf("%d", &num);
        // binary_search
        low = 0;
        high = 19;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (a[mid] == num)
            {
                printf("找到要找的数在数组位置：%d\n", mid);
                break;
            }
            else if (a[mid] > num)
                high = mid - 1;
            else if (a[mid] < num)
                low = mid + 1;
        }
        if (low > high)
            printf("Not found");
    }
    return 0;
}
