#include<stdio.h>
int main()
{
    double x=2.0;
    double square(double y);
    while(x<256.0)
    {
        x=square(x);
        printf("%f\n",x);
    }
}
double square(double y)
{
    return(y*y);
}