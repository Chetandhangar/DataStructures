#include <stdio.h>
#include <stdlib.h>

 void swap(int *x , int *y)
 {
     int temp=*x;
     *x=*y;
     *y=temp;
 }

 void BubbleSort(int A[], int n)
 {
     int flag;
     for(int i=0;i<n-1;i++)
     {
        flag=0;
         for(int j=0;j<n-i-1;j++)
         {
             if(A[j]>A[j+1])
             {
                swap(&A[j],&A[j+1]);
                flag=1;
             }
         }
         if(flag==1)
            break;
     }
 }


int main()
{
    int A[]={2,2,7,12,2,9,23},n=7,i;
    BubbleSort(A,n);
    for(i=0;i<n;i++)
        printf("%d\n",A[i]);
    return 0;
}
