#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>
typedef struct item
{
    int gumption;
    int charisma;
} Item;
#define MAXQUEUE 10
typedef struct node
{
    Item item;
    struct item *next;
} Node;
typedef struct queue
{
    Node *head;
    Node *rear;
    int items;
} Queue;
void IntializeQueue(Queue *pq);
bool QueueIsFull(const Queue *pq);
bool QueueIsEmpty(const Queue *pq);
int QueueItemCount(const Queue *pq);
bool EnQueue(Item item, Queue *pq);
bool DeQueue(Item *pitem, Queue *pq);
void EmptyTheQueue(Queue *pq);
#endif