#include <float.h>
#include <stdio.h>

int main()
{
    printf("char_max=%d\n", (char)0x7f);
    printf("char_min=%d\n", (char)0x80);
    printf("unsigned char_max=%d\n", (unsigned char)0xff);
    printf("long_max=%ld\n", 0x7fffffffl);
    printf("long_min=%ld\n", 0x80000000l);
    printf("double_min=%g\n", 0xffefffffffffffffull);
    printf("double_0-=%g\n", 0x8000000000000001ull);
    printf("double_0+=%g\n", 0x0000000000000001ull);
    printf("double_max=%g\n", 0x7fefffffffffffffull);
    return 0;
}
