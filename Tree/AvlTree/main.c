#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

struct Node *NodeHeight(struct Node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
};

struct Node *BalanceFactor(struct Node *p)
{
    int hl=p->lchild?p->lchild->height:0;
    int hr=p->rchild?p->rchild->height:0;

    return hl-hr;
};
struct Node *LLRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
        root=pl;
    return pl;
};



struct Node *LRRotation(struct Node *p)
{
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->rchild=p;
    plr->lchild=pl;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);
    if(root==p)
        root=plr;

    return plr;
};

struct Node *RRRotation(struct Node *p)
{
    struct Node *pl=p->rchild;
    struct Node *plr=pl->lchild;

    pl->lchild=p;
    p->rchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root==p)
        root=pl;
    return pl;
};

struct Node *RLRotation(struct Node *p)
{
    struct Node *pl=p->rchild;
    struct Node *plr=pl->lchild;

    p->rchild=plr->lchild;
    pl->lchild=plr->rchild;

    plr->rchild=pl;
    plr->lchild=p;

    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    plr->height=NodeHeight(plr);
    if(root==p)
        root=plr;

    return plr;
};

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t=NULL;

    if(t==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node ));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }
    if(key<p->lchild)
        p->lchild=RInsert(p->lchild,key);
    else
        p->rchild=RInsert(p->rchild,key);

      p->height=NodeHeight(p);


      if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);

    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild==1))
        return RLRotation(p);
    else
        return;
    return p;
};


struct Node *Inpre(struct Node *p)
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild ;
    }
    return p;
};

struct Node *Insucc(struct Node *p)
{
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
};

struct Node *Delete(struct Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(root==p)
            root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
        p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(NodeHeight(p->lchild)>NodeHeight(p->rchild))
        {
            q=Inpre(p->lchild);
            p->data=q->data;;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p==1))
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p==-1))
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p==-1))
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p==1))
    return RLRotation(p);

    return p;

};

void Inorder(struct Node *p)
{
    if(p!=NULL)

    {
        Inorder(p->lchild);
        printf("%d\t",p->data);
        Inorder(p->rchild);

    }
}

int main()
{
    root=RInsert(root,10);
    RInsert(root,5);
    RInsert(root,3);
    Delete(root,5);
    Inorder(root);
    //isplay(root);
    return 0;
}
