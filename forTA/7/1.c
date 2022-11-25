#include <stdio.h>
int fun()
{
    //函数每次获取一个字符
    char c = getchar();
    switch (c)
    {
    case '+':
        return fun() + fun();
    case '-':
        return fun() - fun();
    case '*':
        return fun() * fun();
    case '/':
        return fun() / fun();
    default:
        return c - '0'; //将char转换成对应的数
        break;
    }
}
int main()
{
    printf("%d", fun());
    return 0;
}

/*
    比如样例中的 +35
    第一次调用，进入switch case中的 + 后面
    递归调用：
        先调用第一个fun(),此时遇到字符 3 ，则返回数字 3
        再调用第二个fun(),此时遇到字符 5 ，则返回数字 5
    调用结束 返回表达式的值 3 + 5


    +3*34的调用过程:
    fun():
        遇到字符 + 进入 + 对应的内容,计算 fun()+fun()：
            fun():
                遇到字符 3 ,所以本次递归调用返回数字 3
            fun():
                遇到字符 * ,所以进入 * 对应的内容,计算fun()*fun():
                    fun():
                        遇到字符 3 ,返回数字 3
                    fun():
                        遇到字符 4 ,返回数字 4
                返回 3 * 4
        返回 3 + 12

*/