#include <iomanip>
#include <iostream>
#include <unordered_set>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;

unordered_set<long long int> base;
unordered_set<int> counter;
clock_t start, now;

int which_melon[48] = {
    0x1, 0x2, 0x4, 0x7, 0x8, 0x10, 0x20, 0x38, 0x40, 0x80,
    0x100, 0x1c0, 0x49, 0x92, 0x124, 0x1ff, 0x200, 0x400,
    0x800, 0xe00, 0x1000, 0x2000, 0x4000, 0x7000, 0x8000,
    0x10000, 0x20000, 0x38000, 0x9200, 0x12400, 0x24800,
    0x3fe00, 0x201, 0x402, 0x804, 0xe07, 0x1008, 0x2010,
    0x4020, 0x7038, 0x8040, 0x10080, 0x20100, 0x381c0,
    0x9249, 0x12492, 0x24924, 0x3ffff};

void find_num(int remain, long long int now, int bitslocats, int _ans)
{
    if (remain == 0)
    {
        counter.insert(_ans);
        return;
    }
    else if (remain > 48 - bitslocats)
        return;
    for (int i = bitslocats; i < 48; i++)
        find_num(remain - 1, now | (1ULL << i), i + 1, _ans | which_melon[i]);
}

int function(int k)
{
    base.clear();
    find_num(k, 0, 0, 0);
    return counter.size();
}

int main()
{
    start = clock();
    for (int k = 0; k <= 18; k++)
    {
        int answer = function(k);
        now = clock();
        double now_time = (double)(now - start) / CLOCKS_PER_SEC;
        cout << k << " " << std::setw(10) << answer << "\t" << now_time << "s" << endl;
        if (answer >= 262144)
            break;
    }
    return 0;
}