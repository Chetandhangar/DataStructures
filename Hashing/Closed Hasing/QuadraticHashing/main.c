#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int Hash(int key)
{
    return key%SIZE;
}

int Probe(int HT[], int key)
{
    int index=Hash(key);
    int i=0;
    while(HT[(index+i*i)%SIZE]!=0)
          {
              i++;
          }
        return (index+i*i)%SIZE;
}
void Insert(int HT[], int key)
{
    int index=Hash(key);
    if(HT[index]!=0)
        index=Probe(HT,key);
    HT[index]=key;
}

int Search(int HT[], int key)
{
    int i=0;
    int index=Hash(key);
    while(HT[(index+i*i)%SIZE]!=key)
        i++;
    return (index+i*i)%SIZE;
}



int main()
{
    int HT[10]={0};
    Insert(HT,23);
    Insert(HT,43);
    Insert(HT,13);
    Insert(HT,17);
    Insert(HT,47);
    printf("element is foound at index : %d",Search(HT,47));
    return 0;
}
