#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char ch[20];
    size_t a = scanf("%20s", ch);
    printf("%zd\n", a);
    printf("%zd--%zd--%d\n", a, sizeof(ch), strlen(ch));
    for (int i = strlen(ch) - 1; i >= 0; i--)
    {
        /* code */
        printf("%c", ch[i]);
    }

    return 0;
}
