#include <stdio.h>
double abc(float a, float b);
int main(int argc, char const *argv[])
{
    float a, b;
    // scanf("%f%f", &a, &b); // float 类型输入时，不能用%lf;double类型输入时不能用%f
    // printf("%f--%f", a, b);
    while (scanf("%f%f", &a, &b) == 2)
    {
        printf("%lf\n", abc(a, b));
    }
    printf("done!");

    return 0;
}
double abc(float a, float b)
{
    return (a - b) / (a * b);
}