#include <stdio.h>
int main(int argc, char const *argv[])
{
    char ch;
    printf("请输入一个大写字母");
    scanf("%c", &ch);
    for (int i = 0; i <= ch - 'A'; i++)
    {
        printf("%c", 'A');
        for (int j = 1; j <= i; j++)
        {
            printf("%c", 'A' + j);
        }
        for (int k = 1; k <= i; k++)
        {
            printf("%c", 'A' + i - k);
        }
        printf("\n");
    }

    return 0;
}
