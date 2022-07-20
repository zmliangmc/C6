#include <stdio.h>
void cube(double d);
int main()
{
    double dou;
    printf("请输入一个数：");
    scanf("%lf", &dou);
    cube(dou);
    return 0;
}
void cube(double d)
{
    printf("%lf", d * d * d);
}
