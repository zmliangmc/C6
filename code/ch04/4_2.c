#include <stdio.h>
#include <string.h>
int main(void)
{

    char name[40] = "hello world";
    printf("the size of name = %zd,and length of name = %zd", sizeof name, strlen(name));
    return 0;
}