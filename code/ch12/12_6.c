#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 256
int main(int argc, char const *argv[])
{
    char **pt;
    int i, n, length;
    static char temp[LEN];
    printf("how many words do you wish to enter?");
    scanf("%d", &n);
    if ((pt = (char **)malloc(n * sizeof(char *))) != NULL)
    {
        printf("enter %d words now:\n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%255s", temp);
            length = strlen(temp) + 1;
            pt[i] = (char *)malloc(length * sizeof(char));
            if (NULL == pt[i])
            {
                printf("memory allocation failed!");
                exit(EXIT_FAILURE);
            }
            strcpy(pt[i], temp);
        }
        printf("here are your words:\n");
        for (i = 0; i < n; i++)
        {
            puts(pt[i]);
            free(pt[i]);
            pt[i] = NULL;
        }
        free(pt);
        pt = NULL;
    }
    else
    {
        printf("memory allocation failed!");
        exit(EXIT_FAILURE);
    }

    return 0;
}
