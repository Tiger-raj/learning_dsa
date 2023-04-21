#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *Head = NULL;

void create(int A[], int n)
{
    int i;
    Node *p = NULL, *t;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    t = Head;
    for (i = 1; i < n; i++)
    {
        p = new Node;
        p->data = A[i];
        p->next = t->next;
        t->next = p;
        t = p;
    }
}

void Display(Node *h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != Head);
    cout << endl;
}

int Length(Node *p)
{
    int len = 0;
    if (p)
    {
        do
        {
            len++;
            p = p->next;
        } while (p != Head);
    }
    return len;
}

void Insert(Node *p, int index, int x)
{
    Node *t;
    if (index < 0 || index > Length(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        t = new Node;
        t->data = x;
        for (int i = 1; i < index; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    Insert(Head, 1, 1);
    Display(Head);
    return 0;
}