#include <stdio.h>

int main(void)
{
    int feet, fathoms;

    feet = 2;
    fathoms = 6 * feet;
    printf("there are %d fathoms in %d feet", fathoms, feet);

    return 0;
}
