#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *Top = NULL; // creating global top is not a good practise, a good practise would be to create top pointer inside main and pass it as a parameter to the function call.

void push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow!!" << endl;
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

int pop()
{
    Node *p;
    int x = -1;
    if (Top == NULL)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        p = Top;
        x = p->data;
        Top = Top->next;
        free(p);
        p = NULL;
    }
    return x;
}

void display()
{
    Node *p = Top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int peek(int pos)
{
    int i;
    Node *p = Top;
    for (i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}

int stackTop()
{
    if (Top)
    {
        return Top->data;
    }
    return -1;
}

int isEmpty()
{
    return Top ? 0 : 1;
}

int isFull()
{
    Node *t = new Node;
    int r = t ? 0 : 1;
    free(t);
    return r;
}

int main()
{
    push(2);
    push(4);
    push(6);
    push(2);
    push(1);

    display();

    cout << peek(3) << endl;

    cout << pop();
    return 0;
}