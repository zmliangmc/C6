#include <stdio.h>
#define SQUARE(X) X *X
#define PR(X) printf("The result is %d.\n", X)
int main(void)
{
    int x = 5;
    int z;
    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z); // z=25
    z = SQUARE(2);
    printf("Evaluating SQUARE(2): ");
    PR(z); // z=4
    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x + 2)); // 17;预处理器不做计算，不求值，只替换字符序列
    printf("Evaluating 100/SQUARE(2): ");
    PR(100 / SQUARE(2)); // 100/2*2;预处理器不做计算，不求值，只替换字符序列
    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x)); //++x*++x;gcc编译器为49；clang为42
    printf("After incrementing, x is %x.\n", x);
    return 0;
}