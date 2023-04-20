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

void RDisplay(Node *h)
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    // Display(Head);
    RDisplay(Head);
    return 0;
}