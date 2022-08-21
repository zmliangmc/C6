#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SLEN 20
char *s_gets(char *, int);
int main(int argc, char const *argv[])
{
    char ch;
    FILE *fp;
    char name[SLEN];
    fprintf(stdout, "please enter a filename\n");
    while (s_gets(name, SLEN) == NULL || name[0] == '\0')
    {
        puts("please input filename again!");
        continue;
    }
    if ((fp = fopen(name, "r+")) == NULL)
        exit(EXIT_FAILURE);
    while ((ch = getc(fp)) != EOF)
    {
        fseek(fp, -1L, SEEK_CUR);
        putc(toupper(ch), fp);
        fseek(fp, 0L, SEEK_CUR);
    }
    rewind(fp);
    printf("%s filename", name);
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    if (fclose(fp) != 0)
    {
        exit(EXIT_FAILURE);
    }

    return 0;
}
char *s_gets(char *pts, int n)
{
    char *find;
    char *ret_val;
    ret_val = fgets(pts, n, stdin);
    if (ret_val)
    {
        find = strchr(pts, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
