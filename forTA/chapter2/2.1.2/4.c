#include <stdio.h>

int main() {
    char c;
    unsigned short s;
    double d;
    printf("Input one char:");
    c = getchar();
    printf("ASCII:%d\n", c);
    printf("Input one short:");
    scanf("%u", &s); // scanf("%hu", &s);
    printf("unsigned short:%u\n", s);
    printf("Input one real:");
    scanf("%f", &d); // scanf("%lf", &d);
    printf("double:%g\n", d);
    return 0;
}
