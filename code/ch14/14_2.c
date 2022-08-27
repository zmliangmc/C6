#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NLEN 30
struct namect
{
    char *fname;
    char *lname;
    int letters;
};
void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(const struct namect *);
char *s_gets(char *st, int n);
void cleanup(struct namect *);
int main(int argc, char const *argv[])
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}
void getinfo(struct namect *pst)
{
    char temp[NLEN];
    printf("please enter your firstname\n");
    s_gets(temp, NLEN); //如果直接使用pst->fname,就是去了使用malloc的意义。
    pst->fname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->fname, temp);
    printf("please enter your lastname\n");
    s_gets(temp, NLEN);
    pst->lname = (char *)malloc(strlen(temp) + 1);
    strcpy(pst->lname, temp);
}
void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}
void showinfo(const struct namect *pst)
{
    printf("%s%s,your name contains %d letters", pst->fname, pst->lname, pst->letters);
}
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
        {
            *find = '\0';
        }
        else
        {
            while (getchar() != '\n')
            {
                continue;
            }
        }
    }
    return ret_val;
}
void cleanup(struct namect *pst)
{
    free(pst->fname);
    free(pst->lname);
}