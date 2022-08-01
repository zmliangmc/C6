#include <stdio.h>

unsigned long long jiecheng(int n);

int main(int argc, char const *argv[])
{
    /* code */
    unsigned long long m = jiecheng(20);
    printf("%llu", m);
    return 0;
}
unsigned long long jiecheng(int n)
{

    if (n > 1)
        return (unsigned long long)n * (unsigned long long)jiecheng(n - 1);
    else
        return 1;
}