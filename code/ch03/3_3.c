#include <stdio.h>
int main(void)
{
    unsigned int un = 3000000000; /* int为32位和short为16位的系统 */
    short end = 200;
    long big = 65537;
    long long verybig = 12345678908642;
    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("verybig= %lld and not %ld\n", verybig, verybig);
    printf("%d,%d,%d,%d,%d\n", sizeof(int), sizeof(short), sizeof(long), sizeof(long long), sizeof(unsigned long));
    printf("Hello!\032!\n");
    return 0;
}