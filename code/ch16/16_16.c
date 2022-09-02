#include <stdio.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    // clock_t a = clock();
    // printf("%zd\n", a);
    // for (int i = 0; i < 10000000; i++)
    // {
    // }
    // clock_t b = clock();
    // printf("%zd\n", b);
    // printf("%zd\n", (b - a) / CLOCKS_PER_SEC);
    // clock_t c = clock();
    // printf("%zd\n", c);
    int a = time(0);
    printf("%d", a);
    return 0;
}
