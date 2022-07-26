#include <stdio.h>
#define STOP '#'
/*int main(int argc, char const *argv[])
{
    char pre, ch;
    pre = ' ';
    printf("%c", pre);
    int n = 0;
    while ((ch = getchar()) != STOP)
    {
        if (ch == 'i' && pre == 'e')
            n++;
        pre = ch;
    }
    printf("%d", n);
    return 0;
}*/
int main(int argc, char const *argv[])
{
    int n = 0;
    char ch;
    int flag = 0;
    while ((ch = getchar()) != STOP)
    {
        switch (ch)
        {
        case 'e':
            flag = 1;
            break;
        case 'i':
            if (flag == 1)
            {
                n++;
            }
            flag = 0;
            break;
        default:
            flag = 0;
        }
    }
    printf("%d", n);
    return 0;
}
