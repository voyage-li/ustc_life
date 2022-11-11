#include <bits/stdc++.h>
#include <sys/time.h>

void printans(std::vector<std::vector<int>> &s, int i, int j, std::ofstream &outfile)
{
    if (i == j)
        outfile << 'A' << i;
    else
    {
        outfile << '(';
        printans(s, i, s[i][j], outfile);
        printans(s, s[i][j] + 1, j, outfile);
        outfile << ')';
    }
}

int main()
{
    int N = 5;
    long long temp;
    std::ofstream outfile("../output/result.txt");
    std::ofstream timefile("../output/time.txt");
    struct timeval begin, end;
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
        gettimeofday(&begin, 0);
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
        outfile << (long long)m[1][n] << std::endl;
        printans(s, 1, n, outfile);
        outfile << std::endl;
        gettimeofday(&end, 0);
        long seconds = end.tv_sec - begin.tv_sec;
        long microseconds = end.tv_usec - begin.tv_usec;
        double elapsed = seconds + microseconds * 1e-6;
        timefile << std::fixed << std::setw(6) << elapsed << 's' << std::endl;
    }
    outfile.close();
    timefile.close();
    return 0;
}