#include <bits/stdc++.h>
#include <sys/time.h>
int main()
{
    std::ofstream timefile("../output/time.txt");
    struct timeval begin, end;
    for (int base = 1; base <= 5; base++)
    {
        int n;
        std::string p, q;
        std::cin >> n >> p >> q;
        std::string outpath = "../output/result_" + std::to_string(n) + ".txt";
        std::ofstream outfile(outpath);
        p = " " + p;
        q = " " + q;
        int c[n + 1][n + 1];
        char b[n + 1][n + 1];
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        gettimeofday(&begin, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[i] == q[j])
                {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = '\\';
                }
                else if (c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = '|';
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = '-';
                }
            }
        }

        std::string ans = "";
        for (int i = n, j = n;;)
        {
            if (i == 0 || j == 0)
                break;
            if (b[i][j] == '\\')
            {
                ans.push_back(p[i]);
                i = i - 1;
                j = j - 1;
            }
            else if (b[i][j] == '|')
                i = i - 1;
            else
                j = j - 1;
        }
        std::reverse(ans.begin(), ans.end());

        gettimeofday(&end, 0);
        long seconds = end.tv_sec - begin.tv_sec;
        long microseconds = end.tv_usec - begin.tv_usec;
        double elapsed = seconds + microseconds * 1e-6;

        outfile << c[n][n] << std::endl;
        outfile << ans << std::endl;
        timefile << std::fixed << elapsed << 's' << std::endl;
        outfile.close();
    }
    timefile.close();
    return 0;
}