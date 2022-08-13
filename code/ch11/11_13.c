#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int num;
    int i = 0;
    int a;

    while (*(argv[1] + i))
    {

        if (!isdigit(*(argv[1] + i)))
        {
            return 0;
        }
        i++;
    }
    int length = strlen(argv[1]);
    // printf("%d\n", length);
    for (int j = 0; j < length; j++)
    {
        putchar(*(argv[1] + j));
        putchar('\n');
        a = *(argv[1] + j) - '0';
        printf("%d\n", a);
        num += (((int)*(argv[1] + j)) - '0') * (int)pow(10, (length - j - 1));
    }
    printf("%d", num);
    return 0;
}
char *string_in(const char *s1, const char *s2)
{
    char *cp = (char *)s1;
    char *p1, *p2;
    if (!*s2)
        return (char *)s1;
    while (*cp)
    {
        p1 = cp;
        p2 = (char *)s2;
        while (*p1 && *p2 && *p1 == *p2)
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
            return cp;
        cp++;
    }
    return NULL;
}