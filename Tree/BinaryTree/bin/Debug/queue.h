#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

struct Node
{
    struct Node *lchild;
    int data;
    struct Node rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void  Create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(Node **)malloc(q->size*sizeof(Node ));
}

void enequeue(struct Queue *q, Node* x)
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

Node dequeue(struct Queue *q)
{
    Node x=NULL;
    if(q->front==q->rear)
        printf("Queue is empty");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}



#endif // QUEUE_H_INCLUDED
