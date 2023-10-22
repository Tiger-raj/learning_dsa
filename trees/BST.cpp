#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
} *root = NULL;

void Insert(int key)
{
    Node *t = root;
    Node *r, *p = NULL;
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t)
    {
        r = t;
        if (key > t->data)
        {
            t = t->rchild;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (r->data < key)
    {
        r->rchild = p;
    }
    else
    {
        r->lchild = p;
    }
    return;
}

Node *RInsert(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
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

    return p;
}

void Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

Node *SearchKey(int key)
{
    Node *t = root;
    while (t)
    {
        if (key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

int Height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

Node *InPre(Node *p)
{
    p = p->lchild;
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

Node *InSucc(Node *p)
{
    p = p->rchild;
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

Node *Delete(Node *p, int key)
{
    Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

// Creating BST from Preorder

void createPre(int pre[], int n)
{
    stack<Node *> stk;
    Node *t, *p;
    int i = 0;
    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = NULL;
    p = root;
    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new Node;
            t->data = pre[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            stk.push(p);
            p = t;
        }
        else if (pre[i] > p->data)
        {
            int d;
            if (stk.empty())
            {
                d = INT_MAX;
            }
            else
            {
                d = stk.top()->data;
            }
            if (pre[i] < d)
            {
                t = new Node;
                t->data = pre[i++];
                t->lchild = t->rchild = NULL;
                p->rchild = t;
                p = t;
            }
            else
            {
                p = stk.top();
                stk.pop();
            }
        }
    }
}

int main()
{
    /*
    root = RInsert(root, 10);
    root = RInsert(root, 5);
    root = RInsert(root, 20);
    root = RInsert(root, 8);
    root = RInsert(root, 30);

    Delete(root, 20);
    Inorder(root);
    cout << endl;

    Node *p = SearchKey(30);
    if (p)
    {
        cout << "Element is present\n";
    }
    else
    {
        cout << "Element not found !!\n";
    }
    */
    int pre[8] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = 8;
    createPre(pre, n);
    Inorder(root);
    return 0;
}