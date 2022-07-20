#include <stdio.h>
#define M_PER_H 60
int main(void)
{
    int times, hours, mins;
    printf("请输入时间（分钟）输入小于等于0结束");
    scanf("%d", &times);
    while (times > 0)
    {
        /* code */
        hours = times / M_PER_H;
        mins = times % M_PER_H;
        printf("%d--%d---%d\n", times, hours, mins);
        printf("请输入时间（分钟）输入小于等于0结束");
        scanf("%d", &times);
    }
    printf("done!");
    return 0;
}