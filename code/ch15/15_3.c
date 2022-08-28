#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf("%zd\n", _Alignof(double));
    printf("%zd\n", _Alignof(char));
    printf("%zd\n", _Alignof(int));
    printf("%zd\n", _Alignof(long));
    printf("%zd\n", _Alignof(long double));
    printf("%zd\n", _Alignof(float));
    return 0;
}
