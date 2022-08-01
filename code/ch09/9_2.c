#include <stdio.h>
// 递归 recursion
void up_and_down(int n);

int main(int argc, char const *argv[])
{
    up_and_down(4);
    return 0;
}
void up_and_down(int n)
{
    printf("level %d location %p \n", n, &n);
    if (n > 1)
        up_and_down(n - 1);
    printf("level %d location %p \n", n, &n);
}