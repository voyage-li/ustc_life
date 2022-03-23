#include <iostream>
short times(short a, short b)
{
    short flag = -1;
    if (b < 0)
        flag = 1;
    short answer = 0;
    while (b != 0)
    {
        answer += a;
        b += flag;
    }
    return (-flag) * answer;
}
int main()
{
    short a, b;
    std::cin >> a >> b;
    std::cout << times(a, b) << std::endl;
    return 0;
}