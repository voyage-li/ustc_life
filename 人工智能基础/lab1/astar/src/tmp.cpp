#include <bits/stdc++.h>
// #define DEBUG

void reverse(std::vector<std::vector<int>> &data, int n, int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    data[i][j] = !data[i][j];
}

int move(std::vector<std::vector<int>> &data, int i, int j, int s)
{
    int n = data.size();
    if (s == 1)
    {
        if (j + 1 >= n || i - 1 < 0)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i, j + 1);
        reverse(data, n, i - 1, j);
    }
    if (s == 2)
    {
        if (j - 1 < 0 || i - 1 < 0)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i - 1, j);
        reverse(data, n, i, j - 1);
    }
    if (s == 3)
    {
        if (j - 1 < 0 || i + 1 >= n)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i, j - 1);
        reverse(data, n, i + 1, j);
    }
    if (s == 4)
    {
        if (j + 1 >= n || i + 1 >= n)
            return -1;
        reverse(data, n, i, j);
        reverse(data, n, i + 1, j);
        reverse(data, n, i, j + 1);
    }
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> data(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> data[i][j];

    int t;
    std::cin >> t;
    while (t--)
    {
        int i, j, s;
        scanf("%d,%d,%d", &i, &j, &s);
        move(data, i, j, s);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cout << data[i][j];
    return 0;
}