#include <stdio.h>
#include <math.h>
int bstoi(char *);
int main(int argc, char const *argv[])
{
    char *pbin = "01001001";
    int a = bstoi(pbin);
    printf("%d", a);
    return 0;
}
int bstoi(char *bstr)
{
    int i = 0;
    int num = 0;
    while (bstr[i] != '\0')
    {
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        num += (bstr[j] - 48) * pow(2, i - 1 - j);
    }
    return num;
}
