#include <bits/stdc++.h>
int main()
{
    double a;
    int b;
    std::cin >> a >> b;
    for (int i = 0; i < 10; i++)
    {
        a = a * b;
        if (a >= 1)
        {
            if (abs(a) < 10)
                std::cout << abs(a);
            else
            {
                std::cout << (char)(abs(a) - 10 + 'A');
            }
            a = a - abs(a);
        }
        else
        {
            std::cout << 0;
        }
    }
}