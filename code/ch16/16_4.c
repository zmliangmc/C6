#include <stdio.h>
#include <math.h>
#define PR(X, ...) printf("message" #X ":" __VA_ARGS__)
int main(int argc, char const *argv[])
{
    double x = 49;
    double y;
    y = sqrt(x);
    PR(1, "x=%g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
    return 0;
}
