#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool judge(char *p, int n, int begin_x, int begin_y, int end_x, int end_y)
{
    /* 
        if it can be solved when the begin point is A 
        if we can move A to B
        it can also be solved when the begin is B.
     */
    if (begin_x == end_x && begin_y == end_y)
        return true;
    
    p[begin_x * n + begin_y] = '#'; //change this part to avoid second judge

    if (begin_x + 1 < n && p[(begin_x + 1) * n + begin_y] == '.')
        if (judge(p, n, begin_x + 1, begin_y, end_x, end_y))
            return true;

    if (begin_y + 1 < n && p[(begin_x)*n + begin_y + 1] == '.')
        if (judge(p, n, begin_x, begin_y + 1, end_x, end_y))
            return true;

    if (begin_x - 1 >= 0 && p[(begin_x - 1) * n + begin_y] == '.')
        if (judge(p, n, begin_x - 1, begin_y, end_x, end_y))
            return true;

    if (begin_y - 1 >= 0 && p[(begin_x)*n + begin_y - 1] == '.')
        if (judge(p, n, begin_x, begin_y - 1, end_x, end_y))
            return true;

    return false;
}

int main()
{
    int number;
    scanf("%d", &number); //the number of data
    while (number--)
    {
        int n;
        scanf("%d", &n);
        char puzzle[n][n];

        for (int i = 0; i < n; i++)
        {
            getchar(); //avoid '\n'
            for (int j = 0; j < n; j++)
                scanf("%c", &puzzle[i][j]);
        }

        int begin_x, begin_y, end_x, end_y;
        scanf("%d %d %d %d", &begin_x, &begin_y, &end_x, &end_y);

        if (judge(*puzzle, n, begin_x, begin_y, end_x, end_y)) //judge
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}