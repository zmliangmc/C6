#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "12_4.h"
int main(int argc, char const *argv[])
{
    int dice, roll;
    int sides;
    int status;
    srand((unsigned int)time(0));
    printf("Enter the number of sides per die, 0 to stop.\n");
    while (scanf("%d", &sides) == 1 && sides > 0)
    {
        /* code */
        printf("How many dice?\n");
        if ((status = scanf("%d", &dice)) != 1)
        {
            if (status == EOF)
                break;
            else
            {
                printf("You should have entered an integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;
                /* 处理错误的输入 */
                printf("How many sides? Enter 0 to stop.\n");
                continue;
                /* 进入循环的下一轮迭代 */
            }
        }
        roll = roll_n_dice(dice, sides);
        printf("You have rolled a %d using %d %d-sided dice.\n",
               roll, dice, sides);
        printf("How many sides? Enter 0 t stop.\n");
    }
    printf("The rollem() function was called %d times.\n",
           roll_count);
    /* 使用外部变量 */
    printf("GOOD FORTUNE TO YOU!\n");
    return 0;
}
