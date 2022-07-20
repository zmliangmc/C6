#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 0;
    int count = 0;
    int days;
    printf("大于0 的数：");
    scanf("%d", &days);
    while (days <= 0)
    {
        printf("请输入大于0的数！\n");
        scanf("%d", &days);
    }
    while (count++ < days)
    {
        /* code */
        sum = sum + count * count;
        // count++;
    }
    printf("%d", sum);
    return 0;
}
