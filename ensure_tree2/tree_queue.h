#include <stdio.h>
#include <stdlib.h>

struct tree;
struct queue;
typedef tree *tAddr;
typedef queue *Addr;
Addr createQueue();
Addr pop(Addr s);
void push(Addr s, Addr ele);
bool isQueueEmpty(Addr s);
Addr createQueueNode(tAddr t);

struct tree
{
    char ele;
    tAddr left;
    tAddr right;
};

struct queue
{
    tAddr ele;
    Addr next;
};

Addr createQueue()
{
    Addr p;
    p = (Addr)malloc(sizeof(struct queue));
    p->next = NULL;
    return p;
}

Addr pop(Addr s)
{
    // 在这里没有free,用完之后自己手动free
    Addr p, rp;
    if (isQueueEmpty(s))
        return NULL;
    p = s;
    while (p->next->next)
    {
        p = p->next;
    }
    rp = p->next;
    p->next = NULL;
    return rp;
}

void push(Addr s, Addr ele)
{
    ele->next = s->next;
    s->next = ele;
}

bool isQueueEmpty(Addr s)
{
    return s->next == NULL;
}

Addr createQueueNode(tAddr t)
{
    Addr q = (Addr)malloc(sizeof(struct queue));
    q->ele = t;
    q->next = NULL;
    return q;
}