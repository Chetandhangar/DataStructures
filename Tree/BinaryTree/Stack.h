#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void StackCreate(struct Stack *st , int size){

    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size*sizeof(struct Node *));
}

void Push(struct Stack *st, struct Node *x){
 if(st->top==st->size-1)
    printf("Stack OverFlow\n");
 else{
    st->top++;
    st->S[st->top]=x;
 }
}

struct Node *Pop(struct Stack *st){
    struct Node *x=NULL;
    if(st->top==-1)
        printf("Stack Underflow");
    else
    {
        x=st->S[st->top--];
    }
    return x;
}
int isFullstack(struct Stack st){
 return st.top==st.size-1;
}

int  isEmptyStack(struct Stack st){
  if(st.top==-1)
    return 1;
  return 0;
}



#endif // STACK_H_INCLUDED
