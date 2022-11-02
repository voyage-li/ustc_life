#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int gcd(int m, int n)
{
    while (m != n)
    {
        if (m > n)
            m = m - n;
        if (m < n)
            n = n - m;
    }
    return m;
}
int main(int argc, char *argv[])
{
    int i, n, m;
    float a[1000], b[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &a[i], &b[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (b[i] == 0 || ((int)a[i] != a[i]) || ((int)b[i] != b[i]))
        {
            printf("Nan\n");
        }
        else
        {
            m = gcd(a[i], b[i]);
            if (m == 1)
            {
                printf("Simplify\n");
            }
            if (m > 1)
            {
                printf("%d %d\n", (int)a[i] / m, (int)b[i] / m);
            }
        }
    }
    return 0;
}