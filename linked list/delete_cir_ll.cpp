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

int Delete(Node *p, int index)
{
    Node *q = NULL;
    int x;

    if (index < 1 || index > Length(Head))
    {
        return -1;
    }

    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;
        x = Head->data;
        if (p == Head)
        {
            delete Head;
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        for (int i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
        q = NULL;
    }
    return x;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    cout << Delete(Head, 4) << endl;
    Display(Head);
    return 0;
}