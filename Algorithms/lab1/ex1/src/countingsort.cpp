#include <bits/stdc++.h>

#define N 333333
int count[N];

std::vector<int> countingsort(std::vector<int> &arr, int len, int k)
{
    memset(count, 0, sizeof(count));
    std::vector<int> ans(len);
    for (int i = 0; i < len; i++)
        count[arr[i]]++;
    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];
    for (int i = len - 1; i >= 0; i--)
        ans[count[arr[i]]-- - 1] = arr[i];
    return ans;
}
int main()
{
    std::vector<int> a;
    int temp;
    int max = 0;
    while (std::cin >> temp)
    {
        a.push_back(temp);
        max = max < temp ? temp : max;
    }
    std::ofstream file("./output/countingsort/time.txt", std::ios_base::app);
    clock_t start, end;
    start = clock();
    a = countingsort(a, a.size(), max);
    end = clock();
    double endtime = (double)(end - start) / CLOCKS_PER_SEC;
    file << std::fixed << endtime << "s\n";
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
}
