#include <stdio.h>
#define XNAME(n) x##n
#define PRINT_XN(n) printf("x" #n "=%d\n", x##n);
int main(int argc, char const *argv[])
{
    int XNAME(1) = 14; // int x1=14
    int XNAME(2) = 20; // int x2=20;
    int x3 = 30;
    PRINT_XN(1); // printf("x" "1" "=%d\n", x1);
    PRINT_XN(2); // printf("x" "2" "=%d\n", x2);
    PRINT_XN(3); // printf("x" "3" "=%d\n", x3);
    return 0;
}
