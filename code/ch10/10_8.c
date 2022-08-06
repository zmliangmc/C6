#include <stdio.h>
void resort(double *, int);
int main(void)
{
    double d[5] = {1, 2, 3, 4, 5};
    resort(d, 5);
    for (int i = 0; i < 5; i++)
        printf("%.1f--", d[i]);
    return 0;
}
void resort(double *p, int n)
{
    double temp;

    for (int i = 0; i < n / 2; i++)
    {
        temp = p[i];
        p[i] = p[n - i - 1];
        p[n - i - 1] = temp;
    }
}
