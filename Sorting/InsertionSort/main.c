#include <stdio.h>
#include <stdlib.h>

void insertionSort(int A[], int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j=i-1;;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main()
{
   int A[]={11,13,7,2,6,9,4,5,10,3},n=10,i;
   insertionSort(A,n);
    for(i=0;i<n;i++)
    {
        printf("%d\n",A[i]);
    }
    return 0;
}
