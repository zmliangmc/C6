#include <stdio.h>
#define MAX(X, Y) X > Y ? X : Y
#define ABS(X) ((X) < 0 ? -(X) : (X))
#define ISSIGN(X) ((X) == '+' || (X) == '-' ? 1 : 0)
int main(int argc, char const *argv[])
{
    float a = 4;
    float b = 5;
    float e = -1;
    float c = MAX(a, b);
    float d = ABS(e);
    printf("%f--%f\n", c, d);
    char m = '-';
    int n = ISSIGN(m);
    printf("%d", n);

    return 0;
}
