#define printf __mingw_printf
#include <stdio.h>
#include <math.h>
#define RAD_TO_DEG (180 / (4 * atanl(1)))
//泛型平方根函数
#define SQRT(X) _Generic((X), long double \
                         : sqrtl, default \
                         : sqrt, float    \
                         : sqrtf)(X)
//泛型正弦函数，角度的单位为°
#define SIN(X) _Generic((X), long double                  \
                        : sinl((X) / RAD_TO_DEG), default \
                        : sin((X) / RAD_TO_DEG), float    \
                        : sinf((X) / RAD_TO_DEG))
int main(int argc, char const *argv[])
{
    float x = 100.0f;
    double xx = 45.0;
    long double xxx = 45.0l;
    long double y = SQRT(x);
    long double yy = SQRT(xx);
    long double yyy = SQRT(xxx);

    printf("%.17Lf\n", y);
    printf("%.17Lf\n\n", yy);
    printf("%.17Lf\n\n", yyy);
    int i = 45;
    yy = SQRT(i);
    printf("%.17Lf\n\n", yy);
    yyy = SIN(xxx);
    printf("%.17Lf\n\n", yyy);
    return 0;
}
