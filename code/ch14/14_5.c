#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 19
typedef struct
{
    int id;
    char fname[LEN];
    char lname[LEN];
    int stage_num;
    int hit_num;
    int base_num;
    int rbi;
    int hit_rate;
} TEAM;
int read_datas(TEAM players[], int n, FILE *fp);
void count_hit_rate(TEAM players[], int n);
void show_messages(TEAM players[], int n);
static TEAM players[LEN];
int main(int argc, char const *argv[])
{
    int len;
    FILE *fp;
    if ((fp = fopen("data.txt", "r")) == NULL)
    {
        exit(EXIT_FAILURE);
    }
    len = read_datas(players, LEN, fp);
    count_hit_rate(players, len);
    show_messages(players, len);
    if (fclose(fp) != 0)
    {
        fprintf(stderr, "can't close file\n");
    }
    return 0;
}
int read_datas(TEAM players[], int n, FILE *fp)
{
    int count = 0;
    float hit_rate;
    char fname[LEN], lname[LEN];
    int m, stage_num, hit_num, base_num, rbi;
    while (7 == fscanf(fp, "%d %18s %18s %d %d %d %d", &m, fname, lname, &stage_num, &hit_num, &base_num, &rbi) && !feof(fp) && count < n)
    {
        if (players[m].stage_num == 0)
            count++;
        strcpy(players[m].fname, fname);
        strcpy(players[m].lname, lname);
        players[m].id = m;
        players[m].stage_num += stage_num;
        players[m].hit_num += hit_num;
        players[m].base_num += base_num;
        players[m].rbi += rbi;
    }
    return count;
}
void count_hit_rate(TEAM players[], int n)
{
    int i;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            players[i].hit_rate = (float)players[i].hit_num / (float)players->stage_num;
        }
    }
}
void show_messages(TEAM players[], int n)
{
    int i;
    if (0 == n)
    {
        puts("no datas");
    }
    else
    {
        printf("data for all players:\n");
        puts("lists");
        for (i = 0; i < n; i++)
        {
            printf("-4d%-12s%-10s %5d %7d %11d %8d %8.2f\n", players[i].id, players[i].fname, players[i].lname, players[i].stage_num, players[i].base_num, players[i].rbi, players[i].hit_rate);
        }
    }
}