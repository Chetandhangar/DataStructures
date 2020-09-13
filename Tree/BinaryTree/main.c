#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "Stack.h"


struct Node *root=NULL;

void TCreate()
{
    struct Node *p, *t;
    int x;
     struct Queue q;
     Create(&q,100);

    printf("Enter root value");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enequeue(&q,root);

    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d \n", p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->lchild=t->rchild=NULL;
        p->lchild=t;
        enequeue(&q,t);
        }

        printf("Enter right  child of %d \n ", p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct  Node));
            t->data=x;
            t->rchild=t->lchild=NULL;
            p->rchild=t;
            enequeue(&q,t);
        }
    }
}
void preoreder(struct Node *p)
{
    if(p)
    {
        printf("%d  \n",p->data);
        preoreder(p->lchild);
        preoreder(p->rchild);
    }
}

void inorder(struct Node *p)
{
     if(p)
     {
         inorder(p->lchild);
         printf("%d ",p->data);
         inorder(p->rchild);
     }
}

void postorder(struct  Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d  ",p->data);
    }
}
 void  Ipreorder(struct Node *p)
 {
     struct Stack str;
     StackCreate(&str,100);

     while(p  || !isEmptyStack(str))
     {
         if(p)
         {
             printf("%d ", p->data);
             Push(&str,p);
             p=p->lchild;
         }
         else
         {
             p=Pop(&str);
             p=p->rchild;
         }
     }
 }

 void  IInorder(struct Node *p)
 {
     struct Stack str;
     StackCreate(&str,100);

     while(p  || !isEmptyStack(str))
     {
         if(p)
         {

             Push(&str,p);
             p=p->lchild;
         }
         else
         {
             p=Pop(&str);
              printf("%d ", p->data);
             p=p->rchild;
         }
     }
 }

 /*void IInorder(struct Node *p)
 {
     struct Stack str;
     StackCreate(&str,100);

     while(p || isEmptyStack(str))
     {
         if(p)
         {
         Push(&str,p);
         p=p->lchild;
        }
         else
         {
             p=Pop(&str);
             printf("%d ",p->data);
             p=p->rchild;
        }
     }
 }
*/

void LevelOrder(struct Node *root)
{
    struct Queue q;
    Create(&q,100);

    printf("%d  " ,root->data);
    enequeue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);
        if(root->lchild)
        {
            printf("%d  ",root->lchild->data);
            enequeue(&q,root->lchild);
        }
        if(root->rchild)
        {
            printf("%d  ",root->rchild->data);
            enequeue(&q,root->rchild);
        }
    }
}

int TCount(struct Node *root)
{
    int x,y;
    if(root)
    {
        x=TCount(root->lchild);
        y=TCount(root->rchild);
        return x+y+1;
    }
    return 0;
}

int THeight(struct Node *root)
{
    int x=0,y=0;
    if(root)
    {
        x=THeight(root->lchild);
        y=THeight(root->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
}

int LeafNodes(struct Node *p)
{
    int x=0,y=0;
    if(p)
    {
        x=LeafNodes(p->lchild);
        y=LeafNodes(p->rchild);
        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}

int main()
{
    TCreate();
    printf("COunt %d \n",TCount(root));
    printf("Height  of tree is %d",THeight(root));
    printf("No. of Leaf Node are %d",LeafNodes(root));
    //LevelOrder(root);
    //Ipreorder(root);

    //preoreder(root);

    // printf("\nInterative inorder traversal of elements \n");
      //IInorder(root);
    //inorder(root);
   // printf("postorder traversal of elements \n");
    //postorder(root);
    return 0;
}
