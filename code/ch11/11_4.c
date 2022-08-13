#include <stdio.h>
#include <string.h>
int main()
{
    char s[10] = "hello";
    char *p = strstr(s, "o");
    putchar(*p);
    // char *s2 = "helld";
    // char *s3 = strncat(s, s2, 4);
    // int a = strncpy(s, s2, 5);
    // printf("%d\n", a);
    // puts(s3);
    // puts(s);
    // puts(s2);
    return 0;
}
