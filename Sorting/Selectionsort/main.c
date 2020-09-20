#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}

void Seledctionsort(int A[], int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
     swap(&A[i],&A[k]);
    }
}

int main()
{
   int A[]={11,13,7,2,6,6,4,5,10,3},n=10,i;

   Seledctionsort(A,n);

   for(i=0;i<n;i++)
        printf("%d \n",A[i]);
    return 0;
}
