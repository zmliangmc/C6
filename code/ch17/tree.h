#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#define SLEN 20
typedef struct item
{
    char petname[SLEN];
    char petkind[SLEN];
} Item;
#define MAXITEMS 10
typedef struct node
{
    Item item;
    struct node *left;
    struct node *right;
} Trnode;
typedef struct tree
{
    Trnode *root;
    int size;
} Tree;
void InitializeTree(Tree *ptree);
bool TreeIsEmpty(const Tree *ptree);
bool TreeIsFull(const Tree *ptree);
int TreeItemCount(const Tree *ptree);
bool AddItem(const Item *pi, Tree *ptree);
bool InTree(const Item *pi, const Tree *ptree);
bool DeleteItem(const Item *pi, Tree *ptree);
void Traverse(const Tree *ptree, void (*pfun)(Item item));
void DeleteTree(Tree *ptree);
#endif