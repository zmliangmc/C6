#include <stdio.h>
#include <ctype.h>
#define LEN 10
void *test(char *str, int n);
void *test1(char *str, int n);
int main(int argc, char const *argv[])
{

    return 0;
}
void *test(char *str, int n)
{
    int i = 0;
    while (i < n - 1)
    {
        str[i++] = getchar();
    }
    str[i] = '\0';
    return;
}
void *test1(char *str, int n)
{
    int i = -1;
    while (++i < n - 1) // 注意字符数组的下标
    {
        str[i] = getchar();
        if (isspace(str[i]))
        {
            break;
        }
    }
    str[i] = '\0';
    return;
}
char *getword(char *str, int len)
{
    char ch;
    int n = 0;
    char *pt = str;
    while ((ch = getchar()) != EOF && isspace(ch))
        continue; // 跳过第一个非空字符前的所有空白字符
    if (ch == EOF)
        return NULL; // 判断是否读到结尾
    else
    {
        n++;
        *str++ = ch; //指针指向第一个非空字符；
    }
    while ((ch = getchar()) != EOF && !isspace(ch) && (n < len))
    {
        *str++ = ch;
        n++; // 判断是否读到结尾，是否空字符，是否超过字符长度
    }
    *str = '\0';
    if (ch == EOF)
        return NULL; // 判断是否读到结尾
    else
    {
        while (getchar() != '\n')
            continue; // 丢弃单词后面所有字符
        return pt;
    }
}