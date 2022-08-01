#include <stdio.h>
#include <ctype.h>
void attain_pos();
int position(char ch);
int main(int argc, char const *argv[])
{

    return 0;
}
void attain_pos()
{
    char ch;
    int figure;
    while ((ch = getchar()) != EOF)
    {
        figure = position(ch);
        if (figure > 0)
        {
            printf("%c is %d in alphabet.\n", ch, figure);
        }
        else
        {
            printf("%c isn't a letter!\n", ch);
        }
        while (getchar() != '\n')
            continue;
        printf("You can enter again (EOF to quit): ");
    }
    printf("Done.\n");
}
int position(char ch)
{
    if (isalpha(ch))
    {
        if (isupper(ch))
            return ch - 'A' + 1;
        if (islower(ch))
            return ch - 'a' + 1;
    }
    else
    {
        return -1;
    }
}