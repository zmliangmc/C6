#include <stdio.h>
#define SIZE 10
int sum(int *ar, int n);
int sump(int *start, int *end);
int main(void)
{
    int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    int s = sum(marbles, SIZE);
    int s1 = sump(marbles, marbles + SIZE);

    printf("sizeof %s is %d\n", "marbles", sizeof(marbles));
    printf("%d\n", s);
    printf("%d\n", s1);
    return 0;
}
int sum(int *ar, int n)
{
    int s = 0;
    for (int i = 0; i < SIZE; i++)
    {
        s += ar[i];
    }
    printf("%d", sizeof(ar));
    return s;
}
int sump(int *start, int *end)
{
    int s = 0;
    while (start < end) //循环处理的最后一个元素，是end指针指向位置的前一个元素；C保证在给数组分配空间时，指向数组后面第一个位置的指针仍是有效的指针。但对marbles[size]未作任何保证。
    {
        s += *start;
        start++; // 指针变量递增，使其指向下一个元素
    }
    return s;
}