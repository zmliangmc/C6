#include <stdio.h>
#include <string.h>
#define LEN 10
char *s_gets(char *str, char ch);
char *mystrchr(char *str, char ch);
char *cancel(char *str);
int stringIn(char *s1, char *s2);
char *string_in(const char *s1, const char *s2);
void reverse(char *str);
int main(int argc, char const *argv[])
{
    char a[] = "h e l l p n";
    puts(a);
    cancel(a);
    puts(a);
    reverse(a);
    puts(a);
    puts(a);
    return 0;
}
char *s_gets(char *str, char ch)
{
    char *ret_val;
    char *find;
    ret_val = fgets(str, LEN, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
char *mystrchr(char *str, char ch)
{
    while (*str != '\0')
    {
        if (*str != ch)
            ++str;
        else
            return str;
    }
    return NULL;
}
char *mystrcpy(char *s1, char *s2, int n)
{
    int count = 0;
    while (*s2 != '\0' && count < n)
    {
        *(s1 + count) = *s2++;
        count++;
    }
    *(s1 + count) = '\0';
    return s1;
}
int stringIn(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int flag = -1;
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    while (i < s1_len && j < s2_len)
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
        // if(j==s2_len){
        //     flag=-1;
        //     break;
        // }
    }
    return 1;
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
            ++p1, ++p2;
        if (!*p2)
            return cp;
        ++cp;
    }
    return NULL;
}
void reverse(char *str)
{
    char temp;
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        temp = str[i];
        str[i] = str[strlen(str) - 1 - i];
        str[strlen(str) - 1 - i] = temp;
    }
}
char *cancel(char *str)
{
    char *pt = str;
    char *p = pt;
    while (*str)
    {
        if (*str != ' ')
        {
            *pt++ = *str++;
        }
        else
        {
            str++;
        }
    }
    *pt = '\0';
    return p;
}