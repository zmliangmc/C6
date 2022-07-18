#include <stdio.h>
int main(void)
{
    float num;

    num = 3.1415;

    printf("%6.2f\n", num); // spacespace3.14
    printf("%.2f\n", num);  //3.14

    return 0;
}