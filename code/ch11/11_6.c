#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMT 81
void toUpper(char *str);
int countPunt(char *str);
int main(int argc, char const *argv[])
{
    char strs[LIMT];
    char *find;
    fgets(strs, LIMT, stdin);
    find = strchr(strs, '\n');
    if (find)
        *find = '\0';
    toUpper(strs);
    puts(strs);
    int a = countPunt(strs);
    printf("%d", a);
    return 0;
}
void toUpper(char *str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
int countPunt(char *str)
{
    int i = 0;
    while (*str)
    {
        if (ispunct(*str++))
            i++;
        }
    return i;
}