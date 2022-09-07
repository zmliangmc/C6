#include <stdio.h>
#define SIZE 10
int binary_search(const int sorted[], int size, int val);
int main(int argc, char const *argv[])
{
    int num, found;
    int nums[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    puts("please enter a number for searching (q to quit)");
    while (scanf("%d", &num) == 1)
    {
        found = binary_search(nums, SIZE, num);
        if (found == 1)
            printf("%d exits in the array.\n");
        else
            printf("%d not exits in the array.\n");
        puts("you can enter again (q to quit):");
    }
    puts("done");
    return 0;
}
int binary_search(const int sorted[], int size, int val)
{
    int mid;
    int min = 0;
    int max = size - 1;
    int found = 0;
    while (min < max)
    {
        mid = (min + max) / 2;
        if (val < sorted[mid])
            max = mid - 1;
        else if (val > sorted[mid])
            min = mid + 1;
        else
        {
            found = 1;
            break;
        }
    }
    if (sorted[min] == val)
        found = 1;
    return found;
}