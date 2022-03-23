#include<stdio.h>
int main()
{
    double shu;
    printf("请输入双精度浮点数：\n");
    scanf("%lf",&shu);
    unsigned char *p;
    p=(unsigned char*)&shu;
    int i;
    for(i=sizeof(double)-1;i>=0;i--)
        printf("%02X ",*(p+i));
    return 0;
}