#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[] = "hello";
    printf("%d  %s;%d\n", sizeof name, name, strlen(name));
    char sex[10];
    scanf("%s", sex);
    printf("%d;%s;%d", sizeof sex, sex, strlen(sex));
    return 0;
}