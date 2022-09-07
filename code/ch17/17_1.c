#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45
struct film
{
    char title[TSIZE];
    int rating;
    struct film *next;
};
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
int main(int argc, char const *argv[])
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];
    puts("Enter first movie title:");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
    {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
        {
            head = current; //把头指针指向当前指针
        }
        else
        {
            prev->next = current; // 把前一个指针指向当前指针
        }
        current->next = NULL; //把当前指针指向下一个指针置为空
        strcpy(current->title, input);
        puts("Enter your rating <0-10>:");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        puts("Enter next movie title (empty line to stop):");
        prev = current; //把当前指针置为前一个指针
    }
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("move:%s rating:%d\n", current->title, current->rating);
        current = current->next;
    }
    current = head;
    while (current != NULL)
    {
        current = head;       // 把当前指针移动到头指针上
        head = current->next; // 把头指针移动到当前指针的下一个指针上
        free(current);        //释放下一个指针
    }
    printf("Bye!\n");
    return 0;
}
