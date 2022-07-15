#include <stdio.h>
int main()
{
    int x = 100;
    printf("dec=%d,octal=%o,hex=%x,bin=%b\n", x, x, x, x);
    printf("dec=%#d,octal=%#o,hex=%#x,bin=%b", x, x, x, x);

    return 0;
}