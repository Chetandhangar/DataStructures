#include <stdio.h>
#include <stdlib.h>
#include "Chain.h";

int HashFun(int key)
{
    return key%10;
}

void Insert(struct Node *H[], int key)
{
    int index=HashFun(key);
    InsertSort(&H[index],key);

}

int main()
{
   struct  Node *HT[10]={11,32,43,24,55,76,67,28,39,90};

   for(int i=0;i<10;i++)
    HT[i]=NULL;

    struct Node *temp;
    Insert(HT,12);
    Insert(HT,25);
    Insert(HT,30);
    temp=Search(HT[HashFun(25)],25);
    printf("\m the element  found is %d ", temp->data);
    return 0;
}
