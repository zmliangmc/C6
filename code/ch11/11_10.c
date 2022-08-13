#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define ROWS 5
#define COLS 10
int get_strings(char (*string)[COLS], char **str, int n);
int get_first(void);
int show_menu(void);
int word(char *str);
char *s_gets(char *str, int n);
void origin_output(char (*str)[COLS], int n);
void ascll_output(char **str, int n);
void length_up_output(char **str, int n);
void first_word_output(char **str, int n);

int main(int argc, char const *argv[])
{
    int n, choice;
    char *str[ROWS];
    char strings[ROWS][COLS];
    printf("please enter %d strings(eof to quit):\n", ROWS);
    if ((n = get_strings(strings, str, ROWS)) != 0)
    {
        while ((choice = show_menu()) != 'q')
        {
            switch (choice)
            {
            case 'a':
            {
                origin_output(strings, n);
                break;
            }
            case 'b':
            {
                ascll_output(str, n);
                break;
            }
            case 'c':
            {
                length_up_output(str, n);
                break;
            }
            case 'd':
            {
                first_word_output(str, n);
                break;
            }
            }
        }
    }
    printf("done\n");
    return 0;
}
int get_strings(char (*string)[COLS], char **str, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (s_gets(string[i], COLS) != NULL)
        {
            str[i] = string[i];
        }
        else
        {
            break;
        }
    }
    return i;
}
int get_first(void)
{
    int ch;
    do
    {
        ch = tolower(getchar());
    } while (isspace(ch));
    while (getchar() != '\n')
        continue;
    return ch;
}
int show_menu(void)
{
    int ch;
    printf("+++++++++++++++++++++++++++++\n");
    printf("a) print source strings\n");
    printf("b) print source strings for ASCII\n");
    printf("c) print source strings for lenght\n");
    printf("d) print source strings for the first word\n");
    printf("q) quit\n");
    printf("----------------------------------\n");
    printf("please input your choice");
    ch = get_first();
    while (ch < 'a' || ch > 'd' && ch != 'q')
    {
        printf("please enter a,b,b,d or q:");
        ch = get_first();
    }
    return ch;
}
int word(char *str)
{
    int length = 0;
    bool inword = false;
    while (*str)
    {
        if (!isspace(*str) && !inword)
        {
            inword = true;
            length++;
        }
        else if (!isspace(*str) && inword)
        {
            length++;
        }
        else if (isspace(*str) && inword)
        {
            break;
        }
        str++;
    }
    return length;
}
char *s_gets(char *str, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(str, n, stdin);
    if (ret_val)
    {
        find = strchr(str, '\n');
        if (*find == '\n')
            *find = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
void origin_output(char (*str)[COLS], int n)
{
    int i;
    printf("source strings\n");
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
    putchar('\n');
}
void ascll_output(char **str, int n)
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("print source strings for ascll:\n", n);
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
    putchar('\n');
}
void length_up_output(char **str, int n)
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strlen(str[i]) > strlen(str[j]))
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("print source strings for ascll:\n", n);
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
    putchar('\n');
}
void first_word_output(char **str, int n)
{
    int i, j;
    char *temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (word(str[i]) > word(str[j]))
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    printf("print source strings for ascll:\n", n);
    for (i = 0; i < n; i++)
    {
        puts(str[i]);
    }
    putchar('\n');
}