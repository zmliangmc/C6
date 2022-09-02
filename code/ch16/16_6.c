#include <stdio.h>
// #define GOOD 20
#ifdef GOOD
#include "a.h"
#define MM 20
#else
#include "b.h"
#define MM 10
#endif
#if GOOD == 1
#include "a.h"
#elif GOOD == 2
#include "b.h"
#else
#include "b.h"
#endif
int main(int argc, char const *argv[])
{
    // printf("%d", GOOD);
    return 0;
}
// #undef GOOD