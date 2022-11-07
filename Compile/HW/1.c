#include <math.h>
#include <stdio.h>
int gcd(int a, int c)
{
    while (c != 0)
    {
        int t = (int)a % (int)c;
        a = c;
        c = t;
    }
    return a;
}
int main()
{
    int x, i;
    double m, n;
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        scanf("%lf %lf", &m, &n);
        if (n == 0 || fabs(m - (int)m) > 1e-6 || fabs(n - (int)n) > 1e-6)
        {
            printf("Nan\n");
        }
        else if (gcd(m, n) == 1)
            printf("Simplify\n");
        else
            printf("%d %d\n", (int)m / gcd(m, n), (int)n / gcd(m, n));
    }
}