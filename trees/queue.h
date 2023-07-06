#pragma once // It's a header guard, a preprocessor dirctive to prevent multiple declaration of the header file in a single translation unit (i.e. single c/cpp file). As it can give error, if the header file is included more than one time in a c/cpp file.
// Alternative way (old way) to do same task :
/*

    #ifndef _NODE_H
    #define _NODE_H

        //wrap the whole code here

    #endif

*/
#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node *[q->size];
}

void enqueue(Queue *q, Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "Queue is full\n";
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node *dequeue(Queue *q)
{
    Node *x = NULL;
    if (q->front == q->rear)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
