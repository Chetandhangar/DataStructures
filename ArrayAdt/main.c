#include <stdio.h>
#include <stdlib.h>

struct Array{
  int A[10];
  int size;
  int length;
  };


void Display(struct Array arr)
{
    int i;
    printf("Elements are: \n");
    for(i=0;i<arr.length;i++)
     printf("%d \n",arr.A[i]);
}

void Append(struct Array *arr,int x)
    {
        if(arr->length<arr->size)
            arr->A[arr->length++]=x;
            //arr->length++;
    }

    void Insert(struct Array *arr, int index, int x){
        int i;
        if(index>=0 && index<=arr->length)
        {
            for(i=arr->length;i>index;i--)
                arr->A[i]=arr->A[i-1];
                arr->A[index]=x;
                arr->length++;
        }
    }

    int Delete(struct Array *arr, int index){
        int i;
        int x=0;
        if(index>=0 && index<= arr->length)
        {
              x=arr->A[index];
            for(i=index;i<arr->length;i++)
                arr->A[i]=arr->A[i+1];
                arr->length--;
                return x;
        }
        return x;
    }

    void swap(int *x , int *y){
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    int LinearSearch(struct Array *arr, int key){
        int i;
        printf("Element Found At Index : " );
        for(i=0;i<arr->length;i++){
            if(key==arr->A[i]){
                swap(&arr->A[i],&arr->A[0]);
                return i;
            }
        }
        return -1;
    }

    int BinarySearch(struct Array arr, int key){
        int l,h,mid;
        l=0;
        h=arr.length-1;
         while(l<=h){
            mid = (l+h)/2;
            if(key == arr.A[mid])
                return mid;
            else if(key<arr.A[mid])
                h=mid-1;
            else
                l=mid+1;
         }
        return -1;
}

int RBinarySearch(int a[],int l, int h, int key){
    int mid;

    if(l<=h){
        mid=(l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key<a[mid])
            return RBinarySearch(a,l,mid-1,key);
        else
            return RBinarySearch(a,mid+1,h,key);
    }
     return -1;
}

int Get(struct Array arr, int index){
    if(index >=0 && index < arr.length){
        return arr.A[index];
    }
}
void Set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
}
int Max(struct Array arr){
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
       if(arr.A[i]>max)
         max=arr.A[i];
    }
    return max;

}

int Min(struct Array arr){
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++)
    {
       if(arr.A[i]<min)
         min=arr.A[i];
    }
    return min;

}

int Sum(struct Array arr){
    int total=0;
    int i;
    for(i=0;i<arr.length;i++)
        total = total +arr.A[i];
    return total;
}
float Avg(struct Array arr){

  return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr){
    int *B;
    int i,j;
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0,j=0;i<arr->length;i++)
        arr->A[i]=B[i];
}

void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
}

int InsertSort(struct Array *arr, int x){
 int i= arr->length-1;
  if(arr->length==arr->size)
    return;
  while(x>=0 && arr->A[i]>x)
    {
      arr->A[i+1]=arr->A[i];
      i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(struct Array arr){
    int i;

    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}



void Rearrange(struct Array *arr){
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>=0)j--;
        if(i<j){
        swap(&arr->A[i],&arr->A[j]);
        }
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];

    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    return arr3;
};

struct Array* Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }

    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=k;
    arr3->size=10;
    return arr3;
};

struct Array* Intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=10;
    return arr3;
};

struct Array* Difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 =(struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }

    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];

    arr3->length=k;
    arr3->size=10;
    return arr3;
};

int main()
{
    struct Array arr1={{2,3,12,15,16},10,5};
    struct Array arr2={{4,12,13,15,18},10,5};
    struct Array *arr3;
    arr3=Difference(&arr1,&arr2);
    //arr3=Intersection(&arr1,&arr2);
    //arr3=Union(&arr1,&arr2);
    //arr3=Merge(&arr1,&arr2);
    //struct Array arr={{2,3,4,5,6},10,5};
   //Rearrange(&arr);
    //printf("%d \n" ,isSorted(arr));
    //InsertSort(&arr,10);
    //Reverse2(&arr);
    //Reverse(&arr);
    //printf("%f \n", Avg(arr));
    //printf("%d \n ", Sum(arr));
    //printf("%d \n ", Min(arr));
    //printf("%d \n ", Max(arr));
    //printf("%d \n ", Get(arr,4));
    //Set(&arr,4,10);
    //printf("%d \n ", RBinarySearch(arr.A,0,arr.length,4));
    //printf("%d \n ", BinarySearch(arr,3));
    //Display(arr);
    //printf("%d \n ",LinearSearch(&arr,5));


    //printf("Deleted Element is : %d \n",Delete(&arr,3));
    //Append(&arr,10);
    //Insert(&arr,3,15);
    Display(*arr3);
    return 0;
}
