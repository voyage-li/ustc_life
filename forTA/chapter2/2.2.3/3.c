#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d", &a, &b);
    printf("%d\n", a += a + b); // 7
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", a *= b % c); // 6
    scanf("%d%d", &a, &c);
    printf("%d\n", a /= c - a); // 1
    scanf("%d", &a);
    printf("%d\n", a += a -= a *= a); // 0
    scanf("%d", &a);
    printf("%d\n", a = (a = ++b, a + 5, a / 5)); // 0
    scanf("%d%d", &a, &b);
    printf("%d\n", (a >= b >= 2) ? 1 : 0); // 0
    return 0;
}
