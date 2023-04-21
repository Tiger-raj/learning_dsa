#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

void Create(int A[], int n)
{
    Node *t, *last = NULL;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int Length(Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(Node *p, int index, int x) // index for inserting starts at 0.
{
    Node *t = NULL;
    if (index < 0 || index > Length(first))
    {
        return;
    }

    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        if (first)
        {
            first->prev = t;
        }
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int Delete(Node *p, int index) // index for deleting starts at 1.
{
    Node *t = NULL;
    int x = -1;

    if (index < 1 || index > Length(first))
    {
        return x;
    }

    if (index == 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;
        }
        x = p->data;
        delete p;
        p = NULL;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
        p = NULL;
    }
    return x;
}

void Reverse(Node *p)
{
    Node *temp = NULL;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int a[] = {2, 3, 6, 5, 9, 8};
    Create(a, 6);
    // Insert(first, 6, 1);
    // Delete(first, 2);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}