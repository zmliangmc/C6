#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
    int letters = 0;
    int words = 0;
    bool inword = false;
    char ch;
    float count;
    while ((ch = getchar()) != EOF)
    {
        if (ispunct(ch))
            continue;
        if (isalpha(ch))
            letters++;
        if (!isspace(ch) && !inword)
        {
            words++;
            inword = true;
        }
        if (isspace(ch) && inword)
            inword = false;
    }
    count = (float)letters / words;
    return 0;
}
