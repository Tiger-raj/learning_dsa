#pragma once
#include "queue.h"
#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(Stack *st, Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

Node *pop(Stack *st)
{
    Node *x = NULL;
    if (st->top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStack(Stack st)
{
    if (st.top == -1)
        return 1;

    return 0;
}

int isFullStack(Stack st)
{
    return st.top == st.size - 1;
}