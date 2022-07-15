#include <stdio.h>
int main()
{
    float a = 3.4e38f;
    float b = a * 100;
    printf("%e", b); // 1.#INF00e+000
    return 0;
}
