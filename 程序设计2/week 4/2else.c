#include <stdio.h>
#include <string.h>
int main()
{
    char source[55];
    char destination[55];
    char *p;
    int number, index;
    scanf("%s", source);
    getchar(); //avoid '\n'
    for (int i = 0;; i++)
    {
        if ((destination[0] = getchar()) == EOF)
            break;
        //avoid '\n' and judge end
        for (index = 1;; index++)
        {
            if ((destination[index] = getchar()) == '\n')
            //the end of scanf
            {
                destination[index] = '\0';
                break;
            }
        }
        number = 0;
        p = destination; //use strstr() to find answer
        while (*p != '\0')
        {
            if (strstr(p, source) != NULL)
            {
                number++;
                p = strstr(p, source);
            }
            else
                break;
            p++;
        }
        printf("%d\n", number);
    }
    return 0;
}