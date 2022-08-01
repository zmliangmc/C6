#include <stdio.h>
void dex_to_bianry(int n);
int main(int argc, char const *argv[])
{
    dex_to_bianry(58);
    return 0;
}
void dex_to_bianry(int n)
{
    int r = n % 2;
    if (n >= 2)
        dex_to_bianry(n / 2);
    if (r)
        printf("1");
    else
        printf("0");
}
