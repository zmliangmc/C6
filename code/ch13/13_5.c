#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    int count = 0;
    double n = 0;
    double sum = 0;
    if (argc == 1)
    {
        fp = stdin;
    }
    else if (argc == 2)
    {
        if ((fp = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "usage %S[filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%lf", &n) == 1)
    {
        sum += n;
        count++;
    }
    if (count > 0)
    {
        printf("average of %d values=%f\n", count, sum / count);
    }
    puts("no valid data"); //该程序没有关闭打开的文件
    return 0;
}
