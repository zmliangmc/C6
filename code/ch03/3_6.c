#include <stdio.h>
int main()
{
    float a = 1.234E10f;
    float b = a / 10;
    printf("%a\n", b); // 0x1.263562p+30
    printf("%e\n", b); // 1.234000e+009

    // float a, b;
    // b = 2.0e7 + 1.0;
    // a = b - 2.0e7;
    // printf("%f　\n", a); // 小于6位是等于1，
    // return 0;
}
