#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUF 256
int has_ch(char ch, const char *line);
int main(int argc, char const *argv[])
{
    FILE *fp;
    char ch;
    char line[BUF];
    if (argc != 3)
    {
        printf("usage: %s character filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    ch = argv[1][0]; // 命令行参数都是字符串
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("can't open %s", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, BUF, fp) != NULL)
    {
        // if (has_ch(ch, line))
        if (strchr(line, ch))
        {
            fputs(line, stdout);
        }
    }
    fclose(fp);
    return 0;
}
int has_ch(char ch, const char *line)
{
    while (*line)
    {
        if (ch == *line++)
            return 1;
    }
    return 0;
}
