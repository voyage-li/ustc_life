#include <stdio.h>

int main() {
    int a, b, c, x, y;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", b > c && b == c); // 0
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", !(a > b) && !c || 1); // 1
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", !(x = a) && (y = b) && 0); // 0
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", !(a + b) + c - 1 && b + c / 2);     // 1
    printf("%d\n", 1 && 30 % 10 >= 0 && 30 % 10 <= 3); // 1
    return 0;
}
