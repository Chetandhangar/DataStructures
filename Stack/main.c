#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st ){

    printf("Enter the size of the Stack");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Push(struct Stack *st, int x){
 if(st->top==st->size-1)
    printf("Stack OverFlow\n");
 else{
    st->top++;
    st->S[st->top]=x;
 }
  return x;
}

void Display(struct Stack st){
    int i=0;
    for(i=st.top;i>=0;i--)
        printf("%d\n",st.S[i]);
}

int Pop(struct Stack *st){
    int i;
    int x=-1;
    if(st->top==-1)
        printf("Stack Underflow");
    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int Peek(struct Stack st, int index){
    int x=-1;
    if(st.top-index+1<0)
        printf("Index Is Invalid");
    else{
        x=st.S[st.top-index+1];
    }
    return x;
};

void isFull(struct Stack st){
 if(st.top==st.size-1)
  printf("Stack is Full\n");
else
    printf("Stack is Not Full\n");
}

void isEmpty(struct Stack st){
if(st.top==-1)
    printf("Stack is Empty\n");
    else
    printf("Stack is not Empty\n");
}

int main()
{
    struct Stack st;
    Create(&st);
    Push(&st,2);
    Push(&st,3);
    Push(&st,4);
    Push(&st,5);
    Push(&st,6);
    //Push(&st,3);
    //Pop(&st);
    printf("%d\n",Peek(st,3));
    Display(st);
    isFull(st);
    isEmpty(st);
    return 0;
}
