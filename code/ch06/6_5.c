#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a;
    double b;
    int c = scanf("%3lf%d", &b, &a);
    printf("%d,%f,%d", a, b, c);
    // double c = 1.2226;
    // printf("%.3f", c);
    return 0;
}
