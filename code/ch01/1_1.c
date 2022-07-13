#include <stdio.h>
int add(int a, int b);
int main()
{
    int dogs;
    scanf("%d", &dogs);
    printf("how many dogs?\n");
    printf("it's %d dogs here\n", dogs);
    int d = add(1, 3);
    printf("%d\n", d);
    int function;
    char a[] = "abcde";
    printf("c%", &a);
    return 0;
}
int add(int a, int b)
{
    int c;
    c = a + b;
    printf("%d\n", c);
    return c;
}