#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

void push(Node **top, char x)
{
    Node *t = NULL;
    t = new Node;
    if (t == NULL)
    {
        cout << "Stack Overflow\n";
        return;
    }
    t->data = x;
    t->next = *top;
    *top = t;
}

char pop(Node **top)
{
    if (*top == NULL)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    char x;
    x = (*top)->data;
    Node *p = *top;
    *top = (*top)->next;
    free(p);
    return x;
}

void display(Node *top)
{
    while (top)
    {
        cout << top->data << endl;
        top = top->next;
    }
    cout << endl;
}

int isBalanced(string exp, Node **top)
{
    int i;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(*top, exp[i]);
        }
    }
}

int main()
{
    Node *Top = NULL;
    string str = "(a+b))-3";
    isBalanced(str, &Top);
    return 0;
}