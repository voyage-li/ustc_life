#include <stdio.h>
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int isf(double a)
{
    if (a - (int)a < 1e-6)
        return 0;
    else
        return 1;
}
int main()
{
    int N;
    scanf("%d", &N);
    double p, q;
    while (N--)
    {
        scanf("%lf %lf", &p, &q);
        if (isf(p) || isf(q) || q == 0)
        {
            printf("Nan\n");
            continue;
        }
        int t = gcd((int)p, (int)q);
        if (t == 1)
        {
            printf("Simplify\n");
            continue;
        }
        printf("%d %d\n", (int)p / t, (int)q / t);
    }
    return 0;
}