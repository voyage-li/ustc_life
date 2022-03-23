#include<stdio.h>
double square(double y)
{
    return(y*y);
}
int main()
{
    double x=2.0;
    while(x<256.0)
    {
        x=square(x);
        printf("%f\n",x);
    }