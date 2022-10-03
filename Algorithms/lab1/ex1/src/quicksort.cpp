#include <bits/stdc++.h>
void quicksort(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int base = arr[left];
    int i = left, j = right;
    int temp;
    while (i < j)
    {
        while (i < j && arr[j] >= base)
            j--;
        while (i < j && arr[i] <= base)
            i++;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[i];
    arr[i] = base;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}
int main()
{
    std::vector<int> a;
    int temp;
    std::ofstream file("./output/quicksort/time.txt", std::ios_base::app);
    clock_t start, end;
    while (std::cin >> temp)
        a.push_back(temp);
    start = clock();
    quicksort(a, 0, a.size() - 1);
    end = clock();
    double endtime = (double)(end - start) / CLOCKS_PER_SEC;
    file << std::fixed << endtime << "s\n";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}
