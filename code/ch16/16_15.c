#include <stdio.h>
#include <stdarg.h>
double sum(int, ...);
int main(int argc, char const *argv[])
{
    double s, t;
    s = sum(3, 1.1, 2.2, 3.3);
    t = sum(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
    printf("%f--%f", s, t);
    return 0;
}
double sum(int n, ...)
{
    double sum = 0;
    va_list ap;
    va_start(ap, n);
    for (int i = 0; i < n; i++)
    {
        sum += va_arg(ap, double);
    }
    va_end(ap);
    return sum;
}
