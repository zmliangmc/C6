#include <stdio.h>
int max(int *, int);
int main(int argc, char const *argv[])
{
    int a[5] = {3, 6, 1, 8, 9};
    int b = max(a, 5);
    printf("%d", b);
    return 0;
}
int max(int *p, int n)
{
    int a = p[0];
    for (int i = 1; i < n; i++)
    {
        if (a < p[i])
            a = p[i];
    }
    return a;
}
