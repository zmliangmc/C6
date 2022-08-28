#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
char *itobs(int, char *);
void show_bstr(char *);
int invert_end(int, int);
int main(int argc, char const *argv[])
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int num;
    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &num) == 1)
    {
        itobs(num, bin_str);
        printf("%d is\n", num);
        show_bstr(bin_str);
        putchar('\n');
        num = invert_end(num, 4);
        printf("Inverting the last 4 bits gives\n");
        show_bstr(itobs(num, bin_str));
        putchar('\n');
    }
    puts("bey");
    return 0;
}
char *itobs(int num, char *pstr)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);
    for (i = size - 1; i >= 0; i--, num >>= 1)
    {
        pstr[i] = (01 & num) + '0';
    }
    pstr[size] = '\0';
    return pstr;
}
void show_bstr(char *pstr)
{
    int i = 0;
    while (pstr[i])
    {
        putchar(pstr[i]);
        if (++i % 4 == 0 && pstr[i])
            putchar(' ');
    }
}
int invert_end(int num, int bit)
{
    int mask = 0, bitval = 1;
    while (bit-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return num ^ mask;
}