#include <stdio.h>
#include <stdlib.h>
#include "queue2.h"
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pitem);
void IntializeQueue(Queue *pq)
{
    pq->head = pq->rear = NULL;
    pq->items = 0;
}
bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}
bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}
int QueueItemCount(const Queue *pq)
{
    return pq->items;
}
bool EnQueue(Item item, Queue *pq)
{
    Node *pnew;
    if (QueueIsFull(pq))
        return false;
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL)
    {
        fprintf(stderr, "unable to allocte memory!\n");
        exit(EXIT_FAILURE);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq))
        pq->head = pnew;
    else
        pq->rear->next = pnew;
    pq->rear = pnew;
    pq->items++;
    return true;
}
bool DeQueue(Item *pitem, Queue *pq)
{
    Node *pt;
    if (QueueIsEmpty(pq))
        return false;
    CopyToItem(pq->head, pitem);
    pt = pq->head;
    pq->head = (Node *)pq->head->next;
    free(pt);
    pq->items--;
    if (pq->items == 0)
        pq->rear = NULL;
    return true;
}
void EmptyTheQueue(Queue *pq)
{
    Item dummy;
    while (!QueueIsEmpty(pq))
    {
        DeQueue(&dummy, pq);
    }
}
static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}
static void CopyToItem(Node *pn, Item *pitem)
{
    *pitem = pn->item;
}