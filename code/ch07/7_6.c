#include <stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int n;

    while (scanf("%d", &n) != 1 || n < 0)
        while (getchar() != '\n')
            continue;
    if (n == 1)
    {
        /* code */
        printf("1既不是素数也不是合数");
        return;
    }

    for (int i = n; i > 1; i--)
    {
        bool flag = false; /* code */
        for (int j = 2; j < i; j++)
        {
            /* code */
            if (i % j == 0)
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            printf("%d is prime\n", i);
        }
    }

    return 0;
}
