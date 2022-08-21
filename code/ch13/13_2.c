#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(int argc, char const *argv[])
{
    int ch;
    FILE *in, *out;
    char name[LEN];
    int count = 0;
    if (argv < 2)
    {
        fprintf(stderr, "usage:%s filename\n");
        exit(EXIT_FAILURE);
    }
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "i can't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    strcpy(name, argv[1], LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");
    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "i can't open the file \"%s\"\n", name);
        exit(3);
    }
    while ((ch = getc(in)) != EOF)
    {
        if (count++ % 3 == 0)
            putc(ch, out);
    }
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "error in closing files\n");
    }

    return 0;
}
