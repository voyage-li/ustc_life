#include <bits/stdc++.h>

typedef struct IndexItem
{
    int index;
    int start;
    int length;
} IndexItem;

int Search(IndexItem a[], int key, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (a[mid].index >= key && key > a[mid - 1].index)
        return mid;
    else if (key < a[mid].index)
        return Search(a, key, low, mid - 1);
    else
        return Search(a, key, mid + 1, high);
}

int find(int s[], IndexItem list[], int key, int l)
{
    int loc = Search(list, key, 0, l - 1);
    if (loc == -1)
        return -1;
    for (int i = 0; i < list[loc].length; i++)
    {
        if (key == s[list[loc].start + i])
            return list[loc].start + i;
    }
    return -1;
}