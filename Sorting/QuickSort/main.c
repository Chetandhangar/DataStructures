#include <stdio.h>
#include <stdlib.h>


void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int patitioned(int A[], int l, int h)
{
     int pivot=A[l];
     int i=l,j=h;
     do
     {

     do{i++;}while(A[i]<=pivot);
     do{j--;}while(A[j]>pivot);
        if(i<j)swap(&A[i],&A[j]);
        }while(i<j);

     swap(&A[l],&A[j]);
     return j;
}

void Quicksort(int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j=patitioned(A,l,h);
        Quicksort(A,l,j);
        Quicksort(A,j+1,h);
    }
}

int main()
{
    int A[]={11,13,7,2,6,9,4,5,10,3,65532},n=11,i;
    Quicksort(A,0,10);
    for(i=0;i<10;i++)
        printf("%d \n",A[i]);
    return 0;
}
