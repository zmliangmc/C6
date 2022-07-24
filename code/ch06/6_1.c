#include <stdio.h>
int main(void)
{
    int num;
    while (scanf("%d", &num) == 1) // 跳过第一个非空白字符或数字
        ;
    printf("%d", num);
    return 0;
}