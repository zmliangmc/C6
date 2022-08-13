#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    double sum = 1;
    double exp;
    int num, i;
    if (argc != 3)
        puts("参数输入有误");
    else
    {
        exp = atof(argv[1]);
        num = atoi(argv[2]);
        for (i = 0; i < num; i++)
        {
            sum *= exp;
        }
        printf("%f", sum);
    }
    return 0;
}
