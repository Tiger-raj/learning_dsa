#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    printf("Enter size of stack :");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = new int[st->size];
}

void display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow !!\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top < 0)
    {
        printf("Stack Underflow !!");
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

int peek(struct Stack st, int pos)
{
    int x = -1;
    if (pos < 1 || st.top - pos + 1 < 0)
    {
        printf("Invalid position.\n");
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct Stack st)
{
    if (!isEmpty(st))
        return st.s[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    push(&st, 50);

    display(st);

    return 0;
}