#include <stdio.h>
#include <stdlib.h>


void Merge(int A[], int l, int mid, int h)
{
    int i,j,k;
    i=l;j=mid+1;k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];

    }
    for(;i<=mid;i++)
            B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        {
            A[i]=B[i];
        }
}

void IMergesort(int A[], int n)
{
    int p,i,l,h,mid;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        Merge(A,0,p/2-1,n-1);
}

void RMergeZSort(int A[], int l, int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        RMergeZSort(A,l,mid);
        RMergeZSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

int main()
{
    int A[]={11,13,7,12,16,9,24,5,10,3}, n=10, i;
    //IMergesort(A,n);
    RMergeZSort(A,0,9);
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
        printf("\n");
    }
    return 0;
}
