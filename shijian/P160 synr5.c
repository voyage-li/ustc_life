#include<stdio.h>
void zhuanzhi(int (*p)[4])
{
    for(int i=0;i<4;i++)
        for(int j=0;j<2;j++)
        {
            int temp;
            temp=*(*(p+i)+j);
            *(*(p+i)+j)=*(*(p+j)+i);
            *(*(p+j)+i)=temp;
        }
    int temp;
            temp=*(*(p+1)+0);
            *(*(p+1)+0)=*(*(p+0)+1);
            *(*(p+0)+1)=temp;
}
int main()
{
    int p[4][4];
    for(int i=0;i<4;i++)
    {
        printf("请输入第%d行的元素：",i+1);
        for(int j=0;j<4;j++)
            scanf("%d",&p[i][j]);
    }
    zhuanzhi(p);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            printf("%d ",*(*(p+i)+j));
        printf("\n");
    }
}
