#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Hash1(int key)
{
    return key%SIZE;
}
int NearPrime(){
    int n=SIZE;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            n--;
            i=2;
        }
    }
    return n;
}
int Hash2(int key)
{
    int nprime=NearPrime();
    return nprime-(key%nprime);
}
int Probe(int HT[], int key)
{
    int index=Hash1(key);
    int h2=Hash2(key);
    int i=0;
    while(HT[(index+(i*h2))%SIZE]!=0)
    i++;
    return (index+(i*h2))%SIZE;
}
void Insert(int HT[], int key)
{
    int index=Hash1(key);
    if(HT[index]!=0)
        index=Probe(HT,key);
    HT[index]=key;
}

int Search(int HT[], int key)
{
    int i;
    int index=Hash1(key);
    int h2=Hash2(key);
    while(HT[(index + (i*h2))%SIZE]!=key)
        i++;
    return (index + (i*h2))%SIZE;
}
int main()
{
    int HT[10]={0};
    Insert(HT,5);
    Insert(HT,25);
    Insert(HT,15);
    Insert(HT,35);
    Insert(HT,95);
    printf("the element is  found at index: %d",Search(HT,95));
    return 0;
}
