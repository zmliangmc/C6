#include <stdio.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char ch = getchar();
    while (ch != '\n')
    {
        if (isalpha(ch))
        {
            putchar(ch + 1);
        }
        else
        {
            putchar(ch);
        }
        ch = getchar();
    }

    return 0;
}
