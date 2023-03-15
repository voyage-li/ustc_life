#include <bits/stdc++.h>

#define N 333333
int temp[N];

void mergesort(std::vector<int> &arr, int left, int right)
{
    if (right - left <= 1)
        return;
    int mid = left + (right - left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid, right);
    for (int i = left, j = mid, k = left; k < right; k++)
    {
        if (j == right || (i < mid && arr[i] <= arr[j]))
            temp[k] = arr[i++];
        else
            temp[k] = arr[j++];
    }
    for (int i = left; i < right; i++)
        arr[i] = temp[i];
}
int main()
{
    std::vector<int> a;
    int temp;
    std::ofstream file("./output/merge_sort/time.txt", std::ios_base::app);
    clock_t start, end;
    while (std::cin >> temp)
        a.push_back(temp);
    start = clock();
    mergesort(a, 0, a.size());
    end = clock();
    double endtime = (double)(end - start) / CLOCKS_PER_SEC;
    file << std::fixed << endtime << "s\n";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}
