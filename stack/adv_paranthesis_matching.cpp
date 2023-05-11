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
    char temp;
    int i, d;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(top, exp[i]);
        }
        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (*top == NULL)
            {
                return 0;
            }
            temp = pop(top);
            d = exp[i] - temp;
            cout << d << endl;
            if ((temp < 50 && d != 1) || (temp > 50 && d != 2))
            {
                return 0;
            }
        }
    }
    if (*top != NULL)
    {
        return 0;
    }
    return 1;
}

int main()
{
    Node *Top = NULL;
    string str = "((a+b))[-3]";

    if (isBalanced(str, &Top) == 1)
    {
        cout << "Paranthesis are balanced!\n";
    }
    else
    {
        cout << "Paranthesis are not balanced!\n";
    }
    display(Top);
    return 0;
}