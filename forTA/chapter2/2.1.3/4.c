#include <stdio.h>

int main()
{
#define N -1
    printf("%c,%d,%u,%x,%o,%lld,%f,%lf\n", N, N, N, N, N, N, N, N);
#undef N
#define N 255
    printf("%c,%d,%u,%x,%o,%lld,%f,%lf\n", N, N, N, N, N, N, N, N);
#undef N
#define N 255.0
    printf("%c,%d,%u,%x,%o,%lld,%f,%lf\n", N, N, N, N, N, N, N, N);
    return 0;
}
