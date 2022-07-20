#include <stdio.h>
const int LEN = 10;
int main(void)
{
    int num, i = 0;
    printf("请输入一个整数：");
    scanf("%d", &num);
    while (i <= 10)
    {
        printf("%d\t", num + i);
        i++;
    }

    return 0;
}