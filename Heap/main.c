#include <stdio.h>
#include <stdlib.h>

void MaxHeapInsert(int A[], int n)
{
    int i=n;
    int temp=A[i];

    while(i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
void MinHeap(int A[], int n)
{
    int i=n;
    int temp=A[i];

    while(i>1 && temp<A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;

    }
    A[i]=temp;
}

void Display(int A[], int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d  ",A[i]);
    }
}

void Swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int Delete(int A[],int n)
{
    int i,j,x;
    x=A[1];
    A[1]=A[n];
    A[n]=x;
    i=1;
    j=i*2;

    while(j<n-1)
    {
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
        int temp;
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        i=j;
        j=2*i;
        }
        else
            break;
    }
    return x;
}

int main()
{
    int A[]={0,10,20,30,25,5,40,35};
    int i;
   /* for(i=1;i<=7;i++)   //Assumuing that  first element is already present in heap
    {
        MaxHeapInsert(A,i);
    }
    Display(A,7);
    */
    for(i=1;i<=7;i++)   //Assumuing that  first element is already present in heap
    {
        MinHeap(A,i);
    }
    Display(A,7);
    printf("\n");
    printf("\n");
    for(i=7;i>1;i--)
    {
        Delete(A,i);
    }
    printf("Elements after deleting \n");
    Display(A,7);
    return 0;
}
