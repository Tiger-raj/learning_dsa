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
int del(Node *p, int index)
{
    int x = -1, i;
    if (index < 1)
    {
        return -1;
    }
    if (index == 1)
    {
        first = first->next;
        x = p->data;
        delete p;
        return x;
    }
    Node *q = NULL;
    for (i = 0; i < index - 1 && p; i++)
    {
        q = p;
        p = p->next;
    }
    if (p)
    {
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
int main()
{
    create(5);
    del(first, 3);
    display(first);
    return 0;
}