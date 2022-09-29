#include <stdio.h>

int main()
{
    printf("sizeof(long long)=%d\n", sizeof(long long));
    printf("sizeof(long double)=%d\n", sizeof(long double));
    printf("sizeof(1)=%d\n", sizeof(1));
    printf("sizeof('a')=%d\n", sizeof('a'));
    printf("sizeof(1.0)=%d\n", sizeof(1.0));
    return 0;
}
