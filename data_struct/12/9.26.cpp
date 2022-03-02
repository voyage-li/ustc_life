#include <bits/stdc++.h>
//9.26
int Search(int a[], int key, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    if (key == a[mid])
        return mid;
    else if (key > a[mid])
        return Search(a, key, mid + 1, high);
    else
        return Search(a, key, low, mid - 1);
}