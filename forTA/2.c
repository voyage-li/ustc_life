#include <stdio.h>
int main()
{
    double y = 12.34;
    y = 100 - y;
    y = (int)(100 * y) / 100.0;
    if (y > 0 && y < 100)
    {
        if ((10 * y - (int)(10 * y)) < 0.5)
            y = ((int)(10 * y)) / 10.0;
        else
            y = ((int)(10 * y)) / 10.0 + 0.1;
    }
    printf("%f", y);
    return 0;
}