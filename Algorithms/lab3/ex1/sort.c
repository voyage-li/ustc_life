#include <stdio.h>
// 冒泡排序
void BubbleSort(int data[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}
// 插入排序
void InsertionSort(int data[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = data[i];
        int j = i - 1;
        while ((j >= 0) && (data[j] > key))
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}
// 二分查找
// 每次查找区间为 [left,right]
int BinarySearch(int data[], int len, int key)
{
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int middle = left + ((right - left) / 2);
        if (data[middle] > key)
            right = middle - 1;
        else if (data[middle] < key)
            left = middle + 1;
        else
            return middle;
    }
    return -1;
}

int main()
{
    int data[10] = {7, 4, 3, 10, 2, 6, 8, 5, 9, 1};
    BubbleSort(data, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", data[i]);
    printf("\n");

    int data2[10] = {7, 4, 3, 10, 2, 6, 8, 5, 9, 1};
    InsertionSort(data2, 10);
    for (int i = 0; i < 10; i++)
        printf("%d ", data2[i]);
    printf("\n");

    printf("查找7的下标为:%d\n", BinarySearch(data2, 10, 7));
    return 0;
}