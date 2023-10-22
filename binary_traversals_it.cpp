#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void preOrderIt(Node *t)
{
    stack<Node *> st;
    while (t != NULL || !st.empty())
    {
        if (t)
        {
            cout << t->data << " ";
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            t = t->right;
        }
    }
}

void inOrderIt(Node *t)
{
    if (t == NULL)
        return;
    stack<Node *> st;
    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            cout << t->data << " ";
            t = t->right;
        }
    }
}

void postOrderIt(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> s1, s2;
    s1.push(root);
    Node *node;
    while (!s1.empty())
    {
        node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
    while (!s2.empty())
    {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

void levelOrderIt(Node *t)
{
    if (t == NULL)
        return;
    queue<Node *> q;
    cout << t->data << " ";
    q.push(t);
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        if (t->left)
        {
            cout << t->left->data << " ";
            q.push(t->left);
        }
        if (t->right)
        {
            cout << t->right->data << " ";
            q.push(t->right);
        }
    }
}

int count(Node *t)
{
    int x, y;
    if (t)
    {
        x = count(t->left);
        y = count(t->right);
        return x + y + 1; // change this return to if(p->left && p->right){return x+y+1;}else {return x+y;} , to get no. of nodes having degree 2.
    }
    return 0;
}

int main()
{
    Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // postOrderIt(root);
    preOrderIt(root);
    cout << endl;
    inOrderIt(root);
    cout << endl;
    levelOrderIt(root);
    cout << endl;
    cout << count(root);
    return 0;
}