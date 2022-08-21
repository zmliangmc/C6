#include <stdio.h>
#include <stdlib.h>
#define BUF 256
int main(int argc, char const *argv[])
{
    size_t bytes;
    FILE *fs, *fd;
    static char temp[BUF];
    if (argc != 3)
        exit(EXIT_FAILURE);
    if ((fs = fopen(argv[1], "rb")) == NULL)
        exit(EXIT_FAILURE);
    if ((fd = fopen(argv[2], "wb")) == NULL)
        exit(EXIT_FAILURE);
    while ((bytes = fread(temp, sizeof(char), BUF, fs)) > 0)
    {
        fwrite(temp, sizeof(char), bytes, fd);
    }
    fclose(fs);
    fclose(fd);
    return 0;
}
