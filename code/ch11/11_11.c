#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int ch, lower, upper, digit;
    int punct, words;
    lower = upper = digit = 0;
    punct = words = 0;
    bool inword = false;
    while ((ch = getchar()) != EOF)
    {
        if (islower(ch))
            lower++;
        else if (isupper(ch))
            upper++;
        else if (isdigit(ch))
            digit++;
        else if (ispunct(ch))
            punct++;
        if (!isspace(ch) && !inword)
        {
            inword = true;
            words++;
        }
        if (isspace(ch) && inword)
            inword = false;
    }
    printf("%d--%d--%d--%d", lower, upper, punct, words, digit);
    return 0;
}
