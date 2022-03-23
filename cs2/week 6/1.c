#include <stdio.h>
int main()
{
    int number;
    int a, b, c;
    int temp = -1;//record max
    scanf("%d", &number);
    for (a = 0; a <= number; a++)
        for (b = 0; b <= number; b++)
            for (c = 0; c <= number; c++)
                if ((a + b) % 2 == 0 && (b + c) % 3 == 0 && (a + b + c) % 5 == 0)//judge condition
                    temp = (temp > a + b + c) ? temp : (a + b + c);
    if (temp != -1)
        printf("%d", temp);
    else
        printf("-1");//there are no a b c to satisfy condition
    return 0;
}