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
    cout << endl;
}
int count(struct Node *p)
{
    // int c = 0;
    // while (p)
    // {
    //     c++;
    //     p = p->next;
    // }
    // return c;
    if (p)
    {
        return count(p->next) + 1;
    }
    return 0;
}

// REVERSING ELEMENTS

void revE(struct Node *q)
{
    struct Node *p = q;
    int n = count(first), i = 0;
    int arr[n];
    while (p)
    {
        arr[i] = p->data;
        i++;
        p = p->next;
    }
    i--;
    p = q;
    while (p)
    {
        p->data = arr[i];
        i--;
        p = p->next;
    }
}

// REVERSING LINKS

void revL(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

//  RECURSIVE LINK REVERSAL

void revRL(Node *q, Node *p) // call by passing (NULL,first) as argument
{
    if (p)
    {
        revRL(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    create(5);
    display(first);
    revE(first);
    display(first);
    revL(first);
    display(first);
    revRL(NULL, first);
    display(first);
    return 0;
}