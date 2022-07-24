#include <stdio.h>

int main(void)
{
    int i, upper, lower, sum = 0;

    printf("Please input the upper and lower limits: ");
    while (scanf("%d%d", &upper, &lower) == 2 && upper > lower)
    {
        for (i = lower; i <= upper; i++)
            sum += i * i;
        printf("The sums of the squares from %d to %d is %d", lower, upper, sum);
        printf("Please input the upper and lower limits: ");
    }

    printf("Done.\n");

    return 0;
}