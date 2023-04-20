#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int n)
{
    int i;
    struct Node *p, *last;
    first = new Node;
    first->data = 0;
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        p = new Node;
        p->data = i;
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

void display(Node *p)
{
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
void insertSort(Node *p, int x)
{
    Node *q = NULL, *t = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = p;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    create(5);
    insertSort(first, 3);
    display(first);
    return 0;
}