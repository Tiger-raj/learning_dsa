#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

} *first = NULL, *second = NULL, *third = NULL;

void create(int arr[], int s, node *p)
{
    node *q = NULL;
    p = new node;
    first = p;
    p->data = arr[0];
    p->next = NULL;
    int i;
    q = p;
    for (i = 1; i < s; i++)
    {
        p = new node;
        p->data = arr[i];
        p->next = NULL;
        q->next = p;
        q = p;
    }
}

void display(node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int isLoop(node *p)
{
    node *q = p;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int arr[] = {2, 6, 8, 10, 16, 20, 24, 28};
    create(arr, 8, first);
    node *t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next->next->next->next;
    t2->next = t1;
    // display(first);
    if (isLoop(first))
    {
        cout << "Loop is present in LL.\n";
    }
    else
    {
        cout << "Loop is not present in LL.\n";
    }
    return 0;
}