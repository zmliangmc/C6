#include <stdio.h>
void interchange(int *x, int *y);
int max(int a, int b, int c);
int main(int argc, char const *argv[])
{
    int x = 11;
    int y = 10;
    printf("%d----%d\n", x, y);
    printf("%p----%p\n", &x, &y);
    interchange(&x, &y);
    printf("%d----%d\n", x, y);
    printf("%p----%p\n", &x, &y);
    int z = 8;
    int m = max(x, y, z);
    printf("%d", m);
    return 0;
}
void interchange(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int max(int a, int b, int c)
{
    return a > c ? (a > b ? a : b) : c;
}