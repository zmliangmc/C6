#include <stdio.h>
int main()
{
    // float a = 0.1234E-10f;
    // float b = a / 10;
    // printf("%e", b);
    float a, b;
    b = 2.0e7 + 1.0;
    a = b - 2.0e7;
    printf("%f　\n", a); // 小于6位是等于1，
    return 0;
}
