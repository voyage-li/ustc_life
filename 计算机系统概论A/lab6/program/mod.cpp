#include <bits/stdc++.h>
int main()
{
    short num;
    std::cin >> num;
    while (num >= 7)
    {
        num = num / 8 + num % 8;
        if (num == 7)
            num -= 7;
    }
    std::cout << num << std::endl;
    return 0;
}