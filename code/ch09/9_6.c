#include <stdio.h>

double min(double x, double y);
void chline(char ch, int i, int j);
double harmonic_mean(double x, double y);
void larger_of(double *x, double *y);
void reset_num(double *x, double *y, double *z);
int main(int argc, char const *argv[])
{
    // double m = min(2, 3);
    double a, b, c;
    a = 3.2;
    b = 6.2;
    c = 3.0;
    reset_num(&a, &b, &c);
    printf("%.2f---%.2f---%.2f", a, b, c);

    return 0;
}
double min(double x, double y)
{
    return x > y ? y : x;
}
void chline(char ch, int i, int j)
{
    for (int n = 0; n < j; j++)
    {
        for (i = 0; i < j; i++)
            printf("%c", ch);
        printf("\n");
    }
}
double harmonic_mean(double x, double y)
{
    return 2 / (1 / x + 1 / y);
}
void larger_of(double *x, double *y)
{
    if (*x > *y)
    {
        *y = *x;
    }
    else
    {
        *x = *y;
    }
}
void reset_num(double *x, double *y, double *z)
{
    double temp;
    if (*x > *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
    if (*x > *z)
    {
        temp = *x;
        *x = *z;
        *z = temp;
    }
    if (*y > *z)
    {
        temp = *y;
        *y = *z;
        *z = temp;
    }
}
