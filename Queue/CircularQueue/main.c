#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q, int size){
    q->size=size;
     q->front=q->rear=0;
    q->Q=(int *)malloc(q->size*sizeof(int));

}

void enqueue(struct Queue *q, int x){
    if((q->rear+1)%q->size==q->front)
        printf("Queue is full\n");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q){
    int i=q.front+1;
    do
    {
        printf("%d\n",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);

}

int main()
{
    struct Queue q;
    Create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
     Display(q);
    //enqueue(&q,50);
    //enqueue(&q,60);
    //enqueue(&q,30);
    printf("deleted element is: %d \n",dequeue(&q));
       printf("deleted element is: %d \n",dequeue(&q));
    printf("Element after dequeue operation:\n");
    Display(q);
    return 0;
}
