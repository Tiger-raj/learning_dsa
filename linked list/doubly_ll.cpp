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

int main()
{
    int a[] = {2, 3, 6, 5, 9, 8};
    Create(a, 6);
    Display(first);
    cout << Length(first);
    return 0;
}