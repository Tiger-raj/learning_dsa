// Counting no. of nodes in LL

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
int sum(struct Node *p)
{
    int res = 0;
    // while (p)
    // {
    //     res += p->data;
    //     p = p->next;
    // }
    // return res;
    if (p)
    {
        return sum(p->next) + p->data;
    }
    return 0;
}
int max(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT_MIN;
    }
    x = max(p->next);
    if (x > p->data)
    {
        return x;
    }
    return p->data;
}
Node *search(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return search(p->next, key);
}
void insert(Node *p, int index, int x) // index is index of space or position where we want to insert our new node, for 5 nodes, indices will be 0,1,2,3,4,5
{
    Node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int main()
{
    // create(5);
    // cout << count(first) << endl;
    // cout << sum(first) << endl;
    // cout << max(first) << endl;
    // cout << search(first, 2) << endl;
    // display(first);
    insert(first, 0, 5);
    // we can use this insert function to create the entire linked list.
    insert(first, 1, 2);
    insert(first, 2, 6);
    insert(first, 3, 8);
    insert(first, 4, 9);

    display(first);
    return 0;
}