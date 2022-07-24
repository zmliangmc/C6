#include <stdio.h>
int main(int argc, char const *argv[])
{
    for (int i = 9; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            /* code */
            printf("%d * %d = %d ", i, j, i * j);
        }
        printf("\n");
    }
    // for (size_t i = 0; i < count; i++)
    // {
    //     /* code */
    // }

    return 0;
}
