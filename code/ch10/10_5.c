#include <stdio.h>
void copy(float *, float *, float *);
int main()
{
    float a[5] = {1.1, 2.2, 3.3, 4.4, 5};
    float b[5];
    copy(b, a, a + 5);
    for (int i = 0; i < 5; i++)
        printf("%.1f--", b[i]);
    return 0;
}
void copy(float *a, float *b, float *c)
{
    int i = 0;
    while (i < c - a)
    {
        *a++ = *b++;
    }
}