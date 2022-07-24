#include <stdio.h>
#define NUM 10000
int main(int argc, char const *argv[])
{
    double sum1, sum2, a = 1.0;
    for (int i = 1; i <= NUM; i++)
    {
        /* code */
        sum1 += a / i;
        if (i % 2 == 0)
        {
            /* code */
            sum2 += a / i * -1;
        }
        sum2 += a / i;
    }
    printf("%lf----%lf", sum1, sum2);
    return 0;
}
