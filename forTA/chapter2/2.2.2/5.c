#include <stdio.h>

int main() {
    float f = -2.1, g = 3, h = 4;
    int a = 1, b = 2, c = 3.2;
    int d = a = b = c;
    printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
    a *= b /= c += d;
    printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
    f *= g -= h += d;
    printf("f=%f,g=%f,h=%f\n", f, g, h);
    return 0;
}
/*
a=3,b=3,c=3,d=3
a=0,b=0,c=6,d=3
f=8.400000,g=-4.000000,h=7.000000
*/
