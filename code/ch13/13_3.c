#include <stdio.h>
#include <stdlib.h>
#define CTLZ '\032'
#define SLEN 81
int main(int argc, char const *argv[])
{
    char file[SLEN];
    int ch;
    FILE *fp;
    long count, last;
    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);
    if ((fp = fopen(file, "rb")) == NULL)
    {
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != CTLZ && ch != '\r')
        {
            putchar(ch);
        }
    }
    putchar('\n');
    fclose(fp);
    return 0;
}
