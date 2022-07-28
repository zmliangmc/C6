#include <stdio.h>
char get_choice();
char get_first();
int get_int();
void count();
int main(int argc, char const *argv[])
{
    char choice;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            printf("buy low,sell high.\n");
            break;
        case 'b':
            putchar('\a');
            break;
        case 'c':
            count();
            break;
        default:
            printf("program error\n");
        }
    }
    printf("bey!");
    return 0;
}
void count()
{
    int n, i;
    printf("count how far,enter an integer:\n");
    n = get_int();
    for (i = 0; i < n; i++)
    {
        printf("%d\n", i);
    }
    while (getchar() != '\n')
        continue;
}
char get_choice()
{
    char ch;
    printf("Enter the letter of your choice:\n");
    printf("a. advice              b. bell\n");
    printf("c. count               q. quit\n");
    ch = get_first();
    while ((ch > 'c' || ch < 'a') && ch != 'q')
    {
        printf("Please respond with a, b, c, or q.\n");
        ch = get_first();
    }
    return ch;
}
char get_first()
{
    char ch;
    ch = getchar();
    while (ch == ' ')
    {
        ch = getchar();
    }
    while (getchar() != '\n')
        continue;
    return ch;
}
int get_int()
{
    int input;
    char ch;
    while (scanf("%d", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
        {
            putchar(ch);
        }
        printf(" is not an integer.\nPlease enter an ");
        printf("integer value, such as 25, -178, or 3: ");
    }
    return input;
}