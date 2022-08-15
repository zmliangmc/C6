// #include "12_4.h"
#include <stdio.h>
#include <stdlib.h>
int roll_count = 0;
static int rollem(int sides)
{
    int roll;
    roll = rand() % sides + 1;
    ++roll_count;
    return roll;
}
int roll_n_dice(int dice, int sides)
{
    int d;
    int total;
    if (sides < 2)
    {
        /* code */
        printf("need at least 2sides\n");
        return -2;
    }
    if (dice < 1)
    {
        /* code */
        printf("need at least 1dice\n");
        return -1;
    }
    for (d = 0; d < dice; d++)
    {
        total += rollem(sides);
        return total;
    }
}