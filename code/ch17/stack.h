#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>
#define MAXSIZE 100
typedef char Item;
typedef struct stack
{
    Item data[MAXSIZE];
    int top;
} Stack;
void Init(Stack *st);
bool StackIsEmpty(const Stack *st);
bool StackIsFull(const Stack *st);
bool StackPush(Stack *st, Item item);
bool StackPop(Stack *st, Item item);
#endif