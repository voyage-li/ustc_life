#include <bits/stdc++.h>
short judge(int r0)
{
    short i = 2;
    short r1 = 1;
    while (i * i <= r0)
    {
        if (r0 % i == 0)
        {
            r1 = 0;
            break;
        }
        i++;
    }
    return r1;
}
int main()
{
    short num;
    std::cin >> num;
    std::cout << judge(num) << std::endl;
    return 0;
}
