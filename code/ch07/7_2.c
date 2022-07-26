#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    char c;
    long n_chars = 0L;
    int n_words = 0;
    int n_lines = 0;
    int p_lines = 0;
    char pre;
    bool inword = false;
    while ((c = getchar()) != '|')
    {
        n_chars++;
        if (c == '\n')
            n_lines++;
        if (!isspace(c) && !inword)
        {
            n_words++;
            inword = true;
        }
        if (isspace(c) && inword)
            inword = false;
        pre = c;
    }
    if (pre != '\n')
        p_lines++;
    printf("characters = %ld, words = %d, lines = %d,", n_chars, n_words, n_lines);
    printf("partial lines = %d\n", p_lines);
    return 0;
}
