#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    if((fp=fopen("D:\\Codefield\\CODE_C\\C_Single\\file\\P202 synr5.dat","r"))==NULL)
    {
        printf("Can not open the file!\n");
        exit(0);
    }
    int Letter[26];
    for(int i=0;i<26;i++)
        Letter[i]=0;
    char temp;
    int bijiao;
    while(!feof(fp))
    {
        fscanf(fp,"%c",&temp);
        bijiao=(int)temp;
        if(bijiao>=97&&bijiao<=122)
            Letter[bijiao-97]++;
        else if(bijiao<=90&&bijiao>=65)
            Letter[bijiao-65]++;
    }
    for(int i=0;i<26;i++)
        printf("%c%c=%d\n",i+65,i+97,Letter[i]);
}