#include <stdio.h>
#include <math.h>
// #define NDEBUG
// #include <assert.h>
#include <limits.h>
_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
int main(int argc, char const *argv[])
{
    int x, y;
    double z;
    while ((scanf("%d%d", &x, &y)) == 2 && (x != 0 || y != 0))
    {
        z = x * x - y * y;
        // _STATIC_ASSERT(z > 0);
        // assert(z > 0);
        printf("answer is %f", sqrt(z));
        puts("next pair of numbers:");
    }
    puts("done");
    return 0;
}
