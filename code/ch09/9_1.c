#include <stdio.h>
int imax(); //旧时函数声明
int main(int argc, char const *argv[])
{
    int a = imax(3, 4);
    printf("%d", a);
    return 0;
}
int imax(m, n) // 旧时函数定义
int m, n;
{
    return m > n ? m : n;
}
