#include <stdio.h>
int main(int argc, char const *argv[])

{
    char *s;
    char a[] = "hell";
    s = a;
    puts(s);
    for (int i = 0; i < argc; i++)

    {
        puts(argv[i]);
    }
    printf("%d", argc);
    return 0;
}
