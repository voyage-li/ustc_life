#include <bits/stdc++.h>
/*
    一共有48种合取式:
    3*4*4=48
    其中2*3*3的18种的组合可以表示其他任意合取式
    最大的假设空间大小为：2^18-1=262143
*/

int which_melon[48] = {
    0x1,
    0x2,
    0x4,
    0x7,
    0x8,
    0x10,
    0x20,
    0x38,
    0x40,
    0x80,
    0x100,
    0x1c0,
    0x49,
    0x92,
    0x124,
    0x1ff,
    0x200,
    0x400,
    0x800,
    0xe00,
    0x1000,
    0x2000,
    0x4000,
    0x7000,
    0x8000,
    0x10000,
    0x20000,
    0x38000,
    0x9200,
    0x12400,
    0x24800,
    0x3fe00,
    0x201,
    0x402,
    0x804,
    0xe07,
    0x1008,
    0x2010,
    0x4020,
    0x7038,
    0x8040,
    0x10080,
    0x20100,
    0x381c0,
    0x9249,
    0x12492,
    0x24924,
    0x3ffff};

int bitcount(long long unsigned int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n &= (n - 1);
    }
    return count;
}

std::set<long long int> base;
void find_num(int remain, long long int now, int bitslocats)
{
    if (remain == 0)
    {
        base.insert(now);
        std::cout << std::bitset<48>(now) << std::endl;
        return;
    }
    else if (remain > 0 && bitslocats >= 48)
        return;
    else if (remain > 48 - bitslocats)
        return;
    for (int i = bitslocats; i < 48; i++)
        find_num(remain - 1, now | (1ULL << i), i + 1);
}

int function(int k)
{
    int cnt = 0;
    std::set<int> counter;
    base.clear();
    find_num(k, 0, 0);
    for (auto iter : base)
    {
        int ans = 0;
        std::cout << k << ": " << std::bitset<48>(iter) << std::endl;
        for (int j = 0; j < 48; j++)
        {
            if ((iter & (1ULL << j)) != 0)
                ans = ans | which_melon[j];
        }
        counter.insert(ans);
    }
    return counter.size();
}

int main()
{
    for (int k = 1; k <= 18; k++)
    {
        int answer = function(k);
        std::cout << k << " " << answer << std::endl;
    }
    return 0;
}