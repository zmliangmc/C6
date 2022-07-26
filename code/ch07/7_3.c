#include <stdio.h>
#define STOP '#'
int main(int argc, char const *argv[])
{
    int n = 0;
    char ch;
    while ((ch = getchar()) != STOP)
    {
        switch (ch)
        {
        case '.':
            putchar('!');
            n++;
            break;
        case '!':
            putchar('!!');
            n++;
            break;
        default:
            putchar(ch);
        }
    }
    printf("%d", n);
    return 0;
}
