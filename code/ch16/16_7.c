#include <stdio.h>
// #line 20
// #line 20 "cool"
#if __STDC_VERSION__ != 201112L
#error Not c99
#endif
void why_me();
int main(int argc, char const *argv[])
{
    printf("the file is %s\n", __FILE__);
    printf("the date is %s\n", __DATE__);
    printf("the time is %s\n", __TIME__);
    printf("the version is %ld\n", __STDC_VERSION__);
    printf("the func is %s\n", __func__);
    printf("the line is %d\n", __LINE__);

    why_me();
    return 0;
}
void why_me()
{
    printf("the func is %s\n", __func__);
    printf("the line is %d\n", __LINE__);
}