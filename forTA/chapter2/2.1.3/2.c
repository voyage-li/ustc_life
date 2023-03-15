#include <stdio.h>
#define DOUBLE(x) *(double *)&x
int main()
{
    char c;
    long long ll;
    double d;
    printf("%d,%d,%d\n", sizeof(double), sizeof(long), sizeof(long long));
    c = 0x7f;
    printf("char_max=%d\n", c);
    c = 0x80;
    printf("char_min=%d\n", c);
    printf("unsigned char_max=%u\n", 0xff);
    printf("long_max=%d\n", 0x7fffffff);
    printf("long_min=%d\n", 0x80000000);
    ll = 0xffefffffffffffff;
    d = DOUBLE(ll);
    printf("double_min=%g\n", d);
    ll = 0x8000000000000001;
    d = DOUBLE(ll);
    printf("double_0-=%g\n", d);
    ll = 0x0000000000000001;
    d = DOUBLE(ll);
    printf("double_0+=%g\n", d);
    ll = 0x7fefffffffffffff;
    d = DOUBLE(ll);
    printf("double_max=%g\n", d);
}