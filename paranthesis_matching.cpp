#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *next;
} *Top = NULL; // creating global top is not a good practise, a good practise would be to create top pointer inside main and pass it as a parameter to the function call.

void push(char x)
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

char pop()
{
    Node *p;
    char x = -1;
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

int isBalanced(string exp)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (Top == NULL)
                return 0;
            pop();
        }
    }
    if (Top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    string exp = "((a+b)*(c-d)))";
    cout << isBalanced(exp);
    return 0;
}