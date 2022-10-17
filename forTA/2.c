#include <stdio.h>
int main()
{
    int x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, u, v, p;
    for (x = 10; x < 100; x++)
    {
        for (y = 100; y < 1000; y++)
        {
            z = x * y;
            if (z >= 10000)
                continue;
            a = x / 10;
            b = x % 10;
            c = y / 100;
            d = (y - c * 100) / 10;
            e = y % 10;
            f = z / 1000;
            g = (z - 1000 * f) / 100;
            h = (z % 100 - z % 10) / 10;
            i = z % 10;
            int q[10] = {a, b, c, d, e, f, g, h, i};
            p = 1;
            for (i = 0; i < 9; i++)
            {
                for (j = 1; j < 9; j++)
                {
                    if (i != j && q[i] == q[j])
                        p = 0;
                }
            }
            if (x * y == z && p)
            {
                printf("%d*%d=%d\n", x, y, z);
            }
        }
    }
    return 0;
}