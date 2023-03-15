#include <stdio.h>

int main()
{
    int a, b;
    double x, y;
    printf("%f\n", 3.5 + 1 / 2 + 56 % 10); // 9.500000
    scanf("%d", &a);
    printf("%d\n", a++ * 1 / 3); // 1
    scanf("%d%lf%lf", &a, &x, &y);
    printf("%f\n", x + a % 3 * (int)(x + y) % 2 / 4); // 3.500000
    scanf("%d%d%lf%lf", &a, &b, &x, &y);
    printf("%f\n", (float)(a + b) / 2 + (int)x % (int)y); // 5.500000
    return 0;
}
