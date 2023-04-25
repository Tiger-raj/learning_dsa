#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack is full\n";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        x = top->data;
        Node *p = top;
        top = top->next;
        delete p;
    }
    return x;
}

void Stack::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);

    stk.display();
    cout << stk.pop() << endl;
    stk.display();
    return 0;
}