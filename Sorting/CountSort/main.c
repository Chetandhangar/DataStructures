#include <stdio.h>
#include <stdlib.h>

int FindMax(int A[], int n)
{
    int i;
    int max=-33268;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

void CountSort(int A[], int n)
{
    int i,j,max;
    max=FindMax(A,n);
    int *C;
    C=(int *)malloc(sizeof(int )*(max+1));

    for(i=0;i<max+1;i++)
    {
        C[i]=0;
    }

    for(i=0;i<n;i++)
    {
        C[A[i]]++;
    }

    j=0;
    i=0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++]=j;
            C[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3},n=10,i;
    CountSort(A,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}
