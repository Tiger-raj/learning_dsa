#include <bits/stdc++.h>
#include "queue.h"
#include "stack.h"
using namespace std;

struct Node *root = NULL;

void create()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value : ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        printf("%d", p->data);
        inorder(p->rchild);
    }
}
void preorder(Node *p)
{
    if (p)
    {
        printf("%d", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d", p->data);
    }
}

void IPreorder(Node *p)
{
    Stack stk;
    Stackcreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}
void IInorder(Node *p)
{
    Stack stk;
    Stackcreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {

            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

int main()
{
    create();
    IInorder(root);

    return 0;
}
