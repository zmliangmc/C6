#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int *a = (int *)malloc(sizeof(int));
    free(a);
    return 0;
}
