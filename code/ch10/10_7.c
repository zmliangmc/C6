#include <stdio.h>
int max(int *, int);
int main(int argc, char const *argv[])
{
    int a[5] = {3, 16, 1, 8, 0};
    int b = max(a, 5);
    printf("%d", b);
    return 0;
}
int max(int *p, int n)
{

    int i = 0;
    int j;
    int a = p[i];
    int b = a;
    for (; i < n; i++)
    {
        if (a < p[i])
        {
            a = p[i];
            j = i;
        }
        if (b > p[i])
        {
            b = p[i];
            j = i;
        }
    }
    return a - b;
}
