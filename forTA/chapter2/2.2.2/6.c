#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d", &a);
    b = (a = a >= 0 ? a : -a, a++);
    printf("a=%d,b=%d\n", a, b);
    c = (a++, b *= a, ++a);
    printf("a=%d,b=%d,c=%d\n", a, b, c);
    return 0;
}
