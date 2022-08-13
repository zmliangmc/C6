#include <stdio.h>
#define STLEN 10
int main(int argc, char const *argv[])
{
    char world[STLEN];
    int i;
    while (fgets(world, STLEN, stdin) != NULL && world[0] != '\n')
    {
        i = 0;
        while (world[i] != '\n' && world[i] != '\0')
            i++;
        if (world[i] == '\n')
            world[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
        puts(world);
    }
    int a = puts("dong");
    printf("%zd\n", a);
    int b = fputs("donging", stdout);
    printf("%zd", b);
    return 0;
}
