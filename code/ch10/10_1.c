#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int a[10] = {1, 2, 3, 4};
    printf("%d---%d----%d\n", sizeof(a), sizeof(a[0]), sizeof(a) / sizeof(a[0]));
    char s[15] = "hello world";
    printf("%d---%d----%d---%d\n", sizeof(s), sizeof(s[0]), sizeof(s) / sizeof(s[0]), strlen(s));
    printf("%c", s[10]);
    return 0;
}
