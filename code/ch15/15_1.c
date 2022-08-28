#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    unsigned char val = 2;
    unsigned char val1 = ~val;

    char ch = '0';
    printf("%u\n", val1);
    printf("%u\n", val);
    printf("%hu---\n", ~ch);
    printf("%d\n", ch);
    // printf("%d\n", CHAR_BIT);
    printf("%c\n", 1 + '0');
    return 0;
}
