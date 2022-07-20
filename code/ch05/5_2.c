#include <stdio.h>
int main(void)
{
    int x = 5, y = 4;
    int c = x / y;
    double d = (double)x / y;
    // double d = (double)(x / y);
    printf("%d-----%f", c, d);
    return 0;
}