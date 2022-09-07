#include <stdio.h>
#include "stack.h"
void Init(Stack *st)
{
    st->top = 0;
}
bool StackIsEmpty(const Stack *st)
{
    return st->top == 0;
}
bool StackIsFull(const Stack *st)
{
    return MAXSIZE == st->top;
}
bool StackPush(Stack *st, Item item)
{
    if (StackIsFull(st))
        return false;
    st->data[st->top++] = item;
    return true;
}
bool StackPop(Stack *st, Item *pi)
{
    if (StackIsEmpty(st))
        return false;
    *pi = st->data[--st->top];
    return true;
}
