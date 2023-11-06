#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    int height; // we'll take value of height in reverse order of what it's like root having max height and leaf nodes having min height, so as to calculate balance factor for each node
    Node *rchild;
} *root = NULL;

int nodeHeight(Node *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(Node *p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl - hr;
}

Node *LLRotation(Node *p) // to write this function, just make diagram before and after rotation
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }

    return pl;
}

Node *LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);
    if (root == p)
    {
        root == plr;
    }
    return plr;
}
Node *RRRotation(Node *p)
{
    Node *pr = p->rchild, *prl = pr->lchild;

    p->rchild = prl;
    pr->lchild = p;
    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}
Node *RLRotation(Node *p)
{
    Node *pr = p->rchild, *prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    prl->rchild = pr;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);
    prl->height = nodeHeight(prl);

    if (root == p)
    {
        root = prl;
    }
    return prl;
}

Node *RInsert(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = RInsert(p->rchild, key);
    }

    p->height = nodeHeight(p); // at returning time we are updating height of every node as that bf can be calculated using them.

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

int main()
{
    root = RInsert(root, 50);
    root = RInsert(root, 10);
    root = RInsert(root, 20);

    cout << root->data;

    return 0;
}