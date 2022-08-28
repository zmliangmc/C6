#include <stdio.h>
#include <limits.h>
struct word
{
    unsigned int font_id : 8;
    unsigned int font_size : 7;
    unsigned int font_align : 2;
    unsigned int font_bold : 1;
    unsigned int font_itl : 1;
};
int stoi(char *ps)
{
    int num = 0;
    while (*ps)
    {
        num += (num << 1) + *ps++ - '0';
    }
    return num;
}
int count_bit_on(int num)
{
    int count = 0;
    int mask = 01;
    const static int size = CHAR_BIT * sizeof(int);
    for (int i = 0; i < size; i++)
    {
        if (num & mask)
        {
            count++;
        }
        num >>= 1;
    }
    return count;
}
int check_bit(int num, int bit)
{
    for (int i = 0; i < bit; i++)
    {
        num >>= 1;
    }
    return num && 01;
}
int rotate_l(unsigned int num, int bit)
{
    int size = CHAR_BIT * sizeof(int);
    for (int i = 0; i < size; i++)
    {
        num = (num << 1) + ((num >> (size - 1)) & 01);
    }
    return num;
}