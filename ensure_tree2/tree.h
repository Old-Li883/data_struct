#include "tree_queue.h"

tAddr createTreeNode(char ele)
{
    tAddr t;
    t = (tAddr)malloc(sizeof(struct tree));
    t->ele = ele;
    t->left = NULL;
    t->right = NULL;
    return t;
}

tAddr createtree(char a[], int length)
{
    // 通过堆的方式来建立数
    //‘#’表示这个节点为空
    Addr n, n1, n2;
    tAddr t1, t2;
    Addr q = createQueue(); // 先创建一个队列
    tAddr t = createTreeNode(a[0]);
    n = createQueueNode(t);
    push(q, n);
    int i = 0;
    while (!isQueueEmpty(q))
    {
        n = NULL;
        t1 = NULL;
        t2 = NULL;
        if ((a[i] != '#'))
        {
            // i表示当前遍历的树的索引
            // 保证n里面的ele与i所代表的值一致
            n = pop(q);
            // 如果不是最后一排的节点
            if ((a[2 * i + 1] != '#') && (i * 2 + 1 < length))
            {
                // 若此节点的左儿子不为空,创建树的节点,并压栈
                t1 = createTreeNode(a[i * 2 + 1]);
                n1 = createQueueNode(t1);
                push(q, n1);
            }
            if ((a[2 * i + 2] != '#') && (i * 2 + 2 < length))
            {
                t2 = createTreeNode(a[i * 2 + 2]);
                n2 = createQueueNode(t2);
                push(q, n2);
            }
        }
        if (n != NULL)
        {
            // 如果n的节点不为NULL
            // 给这个节点连上左右节点
            n->ele->left = t1;
            n->ele->right = t2;
        }

        i += 1;
    }
    return t;
}

void first(tAddr t)
{
    if (t != NULL)
    {
        printf("%c ", t->ele);
        first(t->left);
        first(t->right);
    }
}

void mid(tAddr t)
{
    if (t != NULL)
    {
        mid(t->left);
        printf("%c ", t->ele);
        mid(t->right);
    }
}

void last(tAddr t)
{
    if (t != NULL)
    {
        last(t->left);
        last(t->right);
        printf("%c ", t->ele);
    }
}

void layer(tAddr t)
{
    tAddr t1;
    Addr n, n1, n2, q;
    q = createQueue();
    n = createQueueNode(t);
    push(q, n);
    while (!isQueueEmpty(q))
    {
        n = pop(q); // 从队列里面弹出节点
        printf("%c ", n->ele->ele);
        if (n->ele->left != NULL) // 如果子节点不为NULL就进队列
        {
            t1 = n->ele->left;
            n1 = createQueueNode(t1);
            push(q, n1);
        }
        if (n->ele->right != NULL)
        {
            t1 = n->ele->right;
            n2 = createQueueNode(t1);
            push(q, n2);
        }
    }
}
