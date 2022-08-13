#include <stdio.h>
#define STLEN 14
int main(int argc, char const *argv[])
{
    char name[STLEN];
    // scanf("%s", name);
    // gets(name);
    fgets(name, STLEN, stdin);
    fputs(name, stdout);
    puts(name);
    fgets(name, STLEN, stdin);
    puts(name);
    fputs(name, stdout);
    puts("done");
    printf("%s", name);
    return 0;
}
