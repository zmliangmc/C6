#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
char get_first();
char get_choice();
float get_float();

int main(int argc, char const *argv[])
{
    char ch;
    float i, j;
    while ((ch = get_choice()) != 'q')
    {
        i = get_float();
        j = get_float();
        switch (ch)
        {
        case 'a':
            printf("%g + %g = %g\n", i, j, i + j);
            break;
        case 's':
            printf("%g - %g = %g\n", i, j, i - j);
            break;
        case 'm':
            printf("%g * %g = %g\n", i, j, i * j);
            break;
        case 'd':
            while (fabs(j) <= 1e-6)
            {
                //↑判断float型浮点数是否为0;
                printf("Enter a number other than 0: ");
                j = get_float();
            }
            printf("%g / %g = %g\n", i, j, i / j);
            break;
        default:
            break;
        }
    }
    printf("Bye.\n");
    return 0;
}
char get_first(void)
{
    int ch;
<<<<<<< HEAD
=======

>>>>>>> 552d6ec35fc5fee7aae7dc71d38ca2664a59ad77
    do
    {
        ch = tolower(getchar());
    } while (isspace(ch));
    while (getchar() != '\n')
        continue;
<<<<<<< HEAD
=======

>>>>>>> 552d6ec35fc5fee7aae7dc71d38ca2664a59ad77
    return ch;
}
char get_choice(void)
{
    int ch;

    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n");
    printf("q. quit\n");
    ch = get_first();

    while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'q')
    {
        printf("Please enter with a,s,m,d or q :");
        ch = get_first();
    }
    return ch;
}
float get_float(void)
{
    int ch;
    float input;

    while (scanf("%f", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not an number.\n");
        printf("Please enter a number such as 2.5, -1.78E8 or 3: ");
    }
    return input;
}