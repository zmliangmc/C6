#include <stdio.h>
#define MYTYPE(X) _Generic((X), int          \
                           : "int", float    \
                           : "float", double \
                           : "double", long  \
                           : "long", default \
                           : "other")
int main(int argc, char const *argv[])
{
    int a;
    printf("%s\n", MYTYPE(5));
    printf("%s\n", MYTYPE(2.0));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&a));
    return 0;
}
