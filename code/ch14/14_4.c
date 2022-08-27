#include <stdio.h>
#include <string.h>
#define LEN 5
#define CSIZE 4
#define SCORES 3
struct name
{
    char fname[LEN];
    char lname[LEN];
};
struct student
{
    struct name mes;
    float scores[SCORES];
    float ave_scores;
};
void set_student(struct student st[], int n);
void find_averages(struct student st[], int n);
void show_messages(const struct student st[], int n);
void show_averages(const struct student st[], int n);
int main(int argc, char const *argv[])
{
    struct student st[CSIZE] = {
        {"flip", "snide"},
        {"job", "dav"},
        {"bingo", "higgs"},
        {"fawn", "maty"}};
    set_student(st, CSIZE);
    find_averages(st, CSIZE);
    show_messages(st, CSIZE);
    show_averages(st, CSIZE);
    return 0;
}
void set_student(struct student st[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < SCORES; j++)
        {
            while (scanf("%f", &st[i].scores[j]) != 1)
            {
                while (getchar() != '\n')
                    continue;
                printf("please enter a number");
            }
        }
    }
}
void find_averages(struct student st[], int n)
{
    int i, j;
    float temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0, temp = 0.0; j < SCORES; j++)
        {
            temp += st[i].scores[j];
        }
        st[i].ave_scores = temp / SCORES;
    }
}
void show_messages(const struct student st[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("\n%s %s's three scores:", st[i].mes.fname, st[i].mes.lname);
        for (j = 0; j < SCORES; j++)
        {
            printf("%g ", st[i].scores[j]);
        }
        printf("\naverage:%g\n", st[i].ave_scores);
    }
}
void show_averages(const struct student st[], int n)
{
    int i;
    float temp = 0;
    for (i = 0; i < n; i++)
    {
        temp += st[i].ave_scores;
    }
    printf("\nclass average:%g", temp / n);
}