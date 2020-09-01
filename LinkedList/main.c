#include<stdio.h>
#include<stdlib.h>

struct Node {
 int data;
 struct Node *next;

}*first=NULL,*second=NULL,*third=NULL;

void Createll(int A[], int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node ));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node ));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }

}

void Createll2(int B[],int n){
    struct Node *last,*t;
     int i;
    second=(struct Node *)malloc(sizeof(struct Node ));
    second->data=B[0];
    second->next=NULL;
    last=second;

      for(i=1;i<n;i++)
        {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last=t;
     }
}

void Display(struct Node *p){
    while(p!=NULL)
        {
        printf("%d \n", p->data);
        p=p->next;
    }
}

void RDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d \n ", p->data);
        RDisplay(p->next);
    }
}

int Count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int RCount(struct Node *p){
    if(p!=NULL)
        return RCount(p->next)+1;
    else
        return 0;

}

int Sum(struct Node *p){
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
        }
    return s;
}

int RSum(struct Node *p){
    if(p!=NULL)
        return RSum(p->next)+p->data;
    else
        return 0;
}

int Max(struct Node *p){
    int m= -32768;
    while(p){
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}
int RMax(struct Node *p){
    int x=0;
    if(p==0)
        return -32768;
    else
        x=RMax(p->next);
    if(x>p->data)
        return x;
    else
        return p->data;
}

int RMax2(struct Node *p){
    int x=0;

     if(p==0)
        return 0;
      x=RMax2(p->next);
      return (x>p->data)?x:p->data;


}

int Min(struct Node *p){
    int min=100;;

    while(p){
        if(p->data<min)
            min=p->data;
         p=p->next;

    }
    return min;
}

struct Node * LSearch(struct Node *p, int key){
    struct Node *q=NULL;
    while(p!=NULL){
        if(key==p->data)
            {
                q->next=p->next;
                p->next=first;
                first=p;
                return p;
            }
            q=p;
            p=p->next;

    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key){
    if(p==0)
        return 0;
    if(key==p->data)
        return p;
    else
       return RSearch(p->next,key);
}

void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;
    if(index <0 || index > Count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0){
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next ;
        t->next=p->next;
        p->next=t;
    }


}

void InsertSort(struct Node *p, int x){
    struct Node *t,*q=NULL;

     t=(struct Node *)malloc(sizeof(struct Node));
     t->data=x;
     t->next=NULL;
     if(first==NULL)
        first=t;
     else{
         while(p && p->data<x)
         {
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
     }

}

int Delete(struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1,i;

    if(index<1 || index > Count(p))
        return -1;
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(i=0;i<index-1;i++){
        q=p;
        p=p->next;
            }

    }
    q->next=p->next;
    x=p->data;
    free(p);
    return x;

}

int IsSorted(struct Node *p){
    int x=-65536;
    while(p!=NULL)
        {
        if(p->data<x)
            return 0;
            else
              x=p->data;
                p=p->next;


    }
    return 1;
}

void RemoveDuplicate(struct Node *p){
    struct Node *q;
    q=p->next;
    while(q!=NULL){

        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }

}

void Reverse(struct Node *p){
    int *A,i=0;
    struct Node *q=p;

    A=(int *)malloc(sizeof(int)*Count(p));
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;

    }
}

void Reverse2(struct Node *p){
    struct Node *r=NULL,*q=NULL;
    int i=0;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

}

void RReverse(struct Node *q, struct Node *p){
    if(p!=NULL){
        RReverse(p,p->next);
        p->next=q;
    }
    else first=q;
}

void Concat(struct Node *p, struct Node *q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;

}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
        third=last=q;
        q=q->next;
        third->next=NULL;

    while(p&&q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}

int IsLoop(struct Node *f)
{
    struct Node *p,*q;

    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
        if(p==q)
        return 1;
       else
        return 0;


}

int main()
{
 //struct Node *temp;
 struct Node *t1,*t2;
 int A[]={10,20,30,40,50};
 Createll(A,5);
 t1=first->next->next->next;
 t2=first->next->next->next->next;
 t2->next=t1;

 printf("%d\n",IsLoop(first));

 /*int B[]={15,18,25,30,55};
 Createll2(B,5);*/

 /*Merge(first,second);
 printf("Elements after Merging two linked list:\n");
 Display(third);*/

 /*Concat(second,first);

 printf("List after Concatination\n");
 Display(third);*/

 //RReverse(NULL,first);
 //Reverse2(first);
 //Reverse(first);
 //RemoveDuplicate(first);
//printf("%d \n",IsSorted(first));

/*if(IsSorted(first)){
    printf("List is sorted");
}
else
    printf("List is not sorted");*/

 //Delete(first,1);
 //InsertSort(first,35);
 //Insert(first,3,10);
 //Insert(first,4,11);

 /*Createll(A,7);
  temp=LSearch(first,15);
  temp=LSearch(first,7);
  if(temp)
    printf("Key is Found %d \n",temp->data);
  else
    printf("Key is Not Found");*/

 //printf("Element is at index Using Recursive: %d \n", RSearch(first,10));
 //printf("Element is at index: %d \n", Search(first,10));
 //printf("Minimum Element is: %d \n", Min(first));
 //printf("Count is: %d \n", RMax2(first));
 //printf("Count is: %d \n", RMax(first));
 //printf("Max Element is: %d \n", Max(first));
 //printf(//"Count is: %d \n", RSum(first));
 //printf("Count is: %d \n", Sum(first));
 //printf("Count is: %d \n", RCount(first));
 //printf("Count is: %d \n", Count(first));
 //RDisplay(first);

 /*printf("Element of First List\n");
 Display(first);
 printf("Element of Second list\n");
 Display(second);*/

return 0;
}
