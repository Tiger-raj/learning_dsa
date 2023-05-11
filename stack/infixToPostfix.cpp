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
    if (pos < 1)
        return -1;
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

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    return 1;
}
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}
char *convert(char *infix)
{
    char *postfix = new char[strlen(infix) + 1];
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre(infix[i]) > pre(stackTop()))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int eval(char *postfix)
{
    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                push(r);
                break;
            case '-':
                r = x1 - x2;
                push(r);
                break;
            case '*':
                r = x1 * x2;
                push(r);
                break;
            case '/':
                r = x1 / x2;
                push(r);
                break;
            }
        }
    }
    return pop();
}

int main()
{
    // char infix[20] = "a+b*c-d/e";
    char infix[20] = "3*5+6/2-4";
    char *postfix = convert(infix);
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        cout << postfix[i];
    }
    cout << endl;
    cout << eval(postfix);
    return 0;
}