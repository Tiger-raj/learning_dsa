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

void create2(int arr[], int s, node *p)
{
    node *q = NULL;
    p = new node;
    second = p;
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

void concat(node *p, node *q)
{
    third = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(node *p, node *q)
{
    node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (q != NULL)
    {
        last->next = q;
    }
    else
    {
        last->next = p;
    }
}

int main()
{
    int arr[] = {2, 6, 8, 10, 16, 20, 24, 28};
    int arr2[] = {1, 3, 5, 71, 99, 101};
    create(arr, 8, first);
    // display(first);
    create2(arr2, 6, second);
    // display(second);
    // concat(first, second);
    // display(third);
    merge(first, second);
    display(third);
    return 0;
}