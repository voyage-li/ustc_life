#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void find(int *p, int x, int y, int last, int *tempspace, int *max, int *number, int length)
{
    int temp = p[x * length + y];
    (*tempspace)++;
    if (temp + last == 15) //there are no walls left
    {
        p[x * length + y] = -1;
        return;
    }
    else if (p[x * length + y] == -1) // go to the same room
    {
        (*tempspace)--;
        return;
    }
    else
    {
        /* 
            use temp to judge where is the wall,then go to that room,then repeat the judge
            8=B(1000);4=B(0100);2=B(0010) 1=B(0001)
         */

        p[x * length + y] = -1; //avoid repeat judge

        if ((temp & 8) == 0)
            find(p, x + 1, y, 2, tempspace, max, number, length);
        if ((temp & 4) == 0)
            find(p, x, y + 1, 1, tempspace, max, number, length);
        if ((temp & 2) == 0)
            find(p, x - 1, y, 8, tempspace, max, number, length);
        if ((temp & 1) == 0)
            find(p, x, y - 1, 4, tempspace, max, number, length);
    }
}

int main()
{
    //the beginning of the walls
    int wide, length;
    scanf("%d", &wide);
    scanf("%d", &length);

    //insert data
    int room[wide][length];
    for (int i = 0; i < wide; i++)
        for (int j = 0; j < length; j++)
            scanf("%d", &room[i][j]);

    int *tempspace = (int *)malloc(sizeof(int));
    int *max = (int *)malloc(sizeof(int));
    int *number = (int *)malloc(sizeof(int));
    *tempspace = 0; //the space of temp condition
    *number = 0;    //the number of rooms
    *max = 0;       //max room

    for (int i = 0; i < wide; i++)
        for (int j = 0; j < length; j++)
        {
            if (room[i][j] == -1) //use -1 judge that it has already go through this condition
                continue;

            find(*room, i, j, 0, tempspace, max, number, length);

            if (*max < *tempspace)
                *max = *tempspace;

            *tempspace = 0; //tend it to 0 to prepare for the next condition

            (*number)++;
        }
    printf("%d\n%d", *number, *max);
    return 0;
}