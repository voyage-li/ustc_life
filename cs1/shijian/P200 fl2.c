#include<stdio.h>
#include<stdlib.h>
#define TLINE 10
#define LINEP 2
int main(int argc,char *argv[])
{
    int flag,page,line,i;
    char buf[100];
    FILE *fp;
    if(argc<2)
    {
        printf("\nNo file name\n");
        exit(0);
    }
    if((fp=fopen(argv[1],"r"))==0)
    {
        printf("\nCan't open file \n");
        exit(0);
    }
    flag=page=line=1;
    while(flag)
    {
        for(i=0;i<LINEP;i++)
            printf("\n");
        printf("%s\n",argv[1]);
        for(i=0;i<TLINE;i++)
        {
            if((fgets(buf,80,fp))==0)
                flag=0;
            if(flag)
            {
                printf("%6d %s",line++,buf);
                if(buf[78]!=0)
                    printf("\n");
            }
            else
                for(i+=2;i<TLINE;i++)  
                    printf("\n");
        }
        printf("\n%65s%d.\n",".",page++);
        for(i=0;i<LINEP;i++)
            printf("\n");
    }
    fclose(fp);
}