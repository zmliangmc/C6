#include <stdio.h>
void copy(double *, double *, double *);
int main()
{
    double a[2][2] = {{1, 2}, {3, 4}};
    double b[2][2];
    for (int i = 0; i < 2; i++)
    {
        copy(b[i], a[i], a[i] + 2);
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%.1f   ", b[i][j]);
        putchar('\n');
    }

    return 0;
}
void copy(double *a, double *b, double *c)
{
    int i = 0;
    while (i < c - b)
    {
        *a++ = *b++;
    }
}