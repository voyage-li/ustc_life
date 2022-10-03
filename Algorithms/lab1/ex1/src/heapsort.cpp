#include <bits/stdc++.h>

void swap(std::vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sink(std::vector<int> &arr, int len, int i)
{
    while (2 * i <= len)
    {
        int j = 2 * i;
        if (j < len && arr[j] < arr[j + 1])
            j++;
        if (arr[i] > arr[j])
            break;
        swap(arr, i, j);
        i = j;
    }
}

void heapsort(std::vector<int> &arr, int len)
{
    for (int i = len / 2; i > 0; i--)
        sink(arr, len, i);
    for (int i = len; i > 0; i--)
    {
        swap(arr, 1, i);
        sink(arr, i - 1, 1);
    }
}

int main()
{
    std::vector<int> a;
    int temp;
    a.push_back(0);
    std::ofstream file("./output/heapsort/time.txt", std::ios_base::app);
    clock_t start, end;
    while (std::cin >> temp)
        a.push_back(temp);
    start = clock();
    heapsort(a, a.size() - 1);
    end = clock();
    double endtime = (double)(end - start) / CLOCKS_PER_SEC;
    file << std::fixed << endtime << "s\n";
    for (int i = 1; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}
