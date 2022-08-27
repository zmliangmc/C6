#include <stdlib.h>
#include <stdio.h>
#define ROWS 20
#define COLS 30
#define LEVELS 10
#define LEN 50
const char trans[LEVELS + 1] = " .':~*=&%#";
int clean_distortion(int (*a)[COLS], int rows, int x, int y);
void change(int (*a)[COLS], char (*b)[COLS], int rows);
int main(int argc, char const *argv[])
{
    int row, col;
    FILE *infile;
    char filename[LEN];
    int figure[ROWS][COLS];
    char picture[ROWS][COLS];
    printf("please enter a filename:\n");
    scanf("%49s", filename);
    if ((infile = fopen(filename, "r+")) == NULL)
        exit(EXIT_FAILURE);
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            fscanf(infile, "%d", &figure[row][col]);
        }
    }
    if (ferror(infile))
        exit(EXIT_FAILURE);
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            figure[row][col] = clean_distortion(figure, ROWS, row, col);
        }
    }
    change(figure, picture, ROWS);
    printf("filename %s have been transformed picture\n", filename);
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            putchar(picture[row][col]);
        }
        putchar('\n');
    }
    fseek(infile, 0L, SEEK_END);
    putc('\n', infile);
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            fprintf(infile, "%c", picture[row][col]);
        }
        putc('\n', infile);
    }
    if (fclose(infile))
    {
        fprintf(stderr, "can't close file %s", filename);
    }
    return 0;
}
int clean_distortion(int (*a)[COLS], int rows, int x, int y)
{
    int i = 0, average = 0, cnt = 0, sur = 0;
    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (i = 0; i < 4; i++)
    {
        int dx = x + d[i][0], dy = y + d[i][1];
        if (dx < 0 || dx >= ROWS || dy < 0 || dy >= COLS)
            continue;
        ++sur;
        if (a[x][y] - a[dx][dy] > 1)
        {
            ++cnt, average += a[dx][dy];
        }
    }
    if (cnt != sur)
        return a[x][y];
    return 1.0 * average / cnt + 0.5;
}
void change(int (*a)[COLS], char (*b)[COLS], int rows)
{
    int row, col;
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            b[row][col] = trans[a[row][col]];
        }
    }
}