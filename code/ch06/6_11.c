#include <stdio.h>

int main(void)
{
    int i, upper, lower;

    printf("Please input the upper limits: ");
    scanf("%d", &upper);
    printf("Please input the lower limits: ");
    scanf("%d", &lower);

    printf("%-10s%-10s%-10s\n", "number", "square", "cube");
    for (i = lower; i <= upper; i++)
    {
        printf("%-10d%-10d%-10d\n", i, i * i, i * i * i);
    }
    printf("Done.\n");

    return 0;
}