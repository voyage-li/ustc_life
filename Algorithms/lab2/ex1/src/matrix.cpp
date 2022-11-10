#include <bits/stdc++.h>

void printans(std::vector<std::vector<int>> &s, int i, int j)
{
    if (i == j)
        std::cout << 'A' << i;
    else
    {
        std::cout << '(';
        printans(s, i, s[i][j]);
        printans(s, s[i][j] + 1, j);
        std::cout << ')';
    }
}

int main()
{
    int N = 5;
    long long temp;
    while (N--)
    {
        int n;
        std::cin >> n;
        std::vector<long long> data;
        std::vector<std::vector<long long>> m(n + 1, std::vector<long long>(n + 1, 0));
        std::vector<std::vector<int>> s(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < n + 1; i++)
        {
            std::cin >> temp;
            data.push_back((int)temp);
        }

        for (int l = 2; l <= n; l++)
        {
            for (int i = 1; i <= n - l + 1; i++)
            {
                int j = i + l - 1;
                m[i][j] = INT64_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    temp = m[i][k] + m[k + 1][j] + data[i - 1] * data[k] * data[j];
                    if (temp < m[i][j])
                    {
                        m[i][j] = temp;
                        s[i][j] = k;
                    }
                }
            }
        }
        std::cout << (long long)m[1][n] << std::endl;
        printans(s, 1, n);
        std::cout << '\n';
    }
    return 0;
}