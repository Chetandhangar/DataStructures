#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Node *root=NULL;

void Insert(int key)
{

    struct Node*t,*f=NULL,*p=root;

    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        root=t;

    return;
    }
    while(p){
        f=p;
        if(key==p->data)
        {
            return;
        }
        else if(key<p->data)
         {
             p=p->lchild;
         }
        else
          {
              p=p->rchild;
          }
    }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;

        if(key<f->data)
        {
                f->lchild=t;
         }
        else
        {
            f->rchild=t;
        }
}

void Inorder(struct Node *p)
{
    if(p!=NULL)

    {
        Inorder(p->lchild);
        printf("%d\t",p->data);
        Inorder(p->rchild);

    }
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t=NULL;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data)
    {
        p->lchild=RInsert(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=RInsert(p->rchild,key);
    }
    return p;
}
struct Node *Search(int key)
{
    struct Node *p=root;
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        else if(key<p->data)
            p=p->lchild;
        else
            p=p->rchild;
    }
    return NULL;

}


struct Node *Height(struct Node *p)
{
    int x,y;
    if(p==NULL)return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;

}

struct Node *InPre(struct Node *p)
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    return p;
};

struct Node *RDelete(struct Node *p, int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }

    if(key<p->data)
        p->lchild=RDelete(p->lchild,key);
    else if(key > p->data)
        p->rchild=RDelete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=RDelete(p->lchild,q->data);

        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=RDelete(p->rchild,q->data);
        }
    }
    return p;
};
int main()
{
    struct Node *temp;
    root=RInsert(root,10);
    RInsert(root,12);
    RInsert(root,5);
    RInsert(root,20);
    RInsert(root,30);

    RDelete(root,10);

    Inorder(root);
    temp=Search(20);
        if(temp!=NULL)
            printf("\nelement  %d is found",temp->data);
        else
            printf("element is not found \n");


}
