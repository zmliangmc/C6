#include <stdio.h>
#define SIZE 26
int main(int argc, char const *argv[])
{
    char ch[SIZE];
    for (int i = 0; i < SIZE; i++)
        ch[i] = 'a' + i;
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c ", ch[i]);
    }

    return 0;
}
