#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{

    struct node n1, n2;
    n1.data = 4;
    n1.next = &n2;
    printf("Size of node is %d\n", sizeof(n1));
    printf("%d", sizeof(struct node));
    return 0;
}