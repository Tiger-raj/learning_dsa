#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct node *p, *last = NULL;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main()
{
    int A[5] = {3, 5, 2, 6, 4};
    create(A, 5);
    display(first);
    return 0;
}