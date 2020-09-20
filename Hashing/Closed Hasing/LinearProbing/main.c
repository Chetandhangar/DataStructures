#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Hash(int key)
{
    return key%SIZE;
}

int Probe(int HT[],int key)
{
    int index=Hash(key);
    int i=0;
    while(HT[(index+i)%SIZE]!=0 && i<SIZE)
        {i++;}
        if(HT[index+1]!=0)
            return -1;
        else
       return (index+i)%SIZE;
}
void Insert(int HT[],int key)
{
    int index=Hash(key);
    if(HT[index]!=0)
        index=Probe(HT,key);
    HT[index]=key;
}

int Search(int HT[], int key)
{
    int index=Hash(key);
    int i=0;
    while(HT[(index+i)%SIZE]!=key)
        i++;
    return (index+i)%SIZE;
}

int main()
{
    int HT[10]={0};
    Insert(HT,11);
    Insert(HT,25);
    Insert(HT,35);
    printf("The element Found at index: %d",Search(HT,35));
    return 0;
}
