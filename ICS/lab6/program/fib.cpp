#include <iostream>
int main()
{
    short n;
    std::cin >> n;
    short Fi[3];
    Fi[0] = 1;
    Fi[1] = 1;
    Fi[2] = 2;
    n -= 2;
    for (; n > 0; n--)
    {
        short temp = Fi[0] << 1;
        Fi[0] = Fi[1];
        Fi[1] = Fi[2];
        Fi[2] = (Fi[1] + temp) % 1024;
    }
    if (n < 0)
        std::cout << Fi[1] << std::endl;
    else
        std::cout << Fi[2] << std::endl;
    return 0;
}