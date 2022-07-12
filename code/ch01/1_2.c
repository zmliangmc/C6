#include <stdio.h>
int main(void)
{
    /* code */
    double in, cm;
    printf("请输入需要转化的英寸数值：");
    scanf("%lf", &in);
    cm = in * 2.54;
    printf("%lf 英寸等于 %lf 厘米", in, cm);
    return 0;
}