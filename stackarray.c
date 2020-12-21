#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10;

typedef struct stack
{
 int top;
 int capacity;
 int *array;
}STACK;

STACK *createstack()
{
 STACK *s;
 s=(STACK *)malloc(sizeof(STACK));
 s->top=-1;
 s->capacity=MAXSIZE;
 s->array=malloc(s->capacity*sizeof(int));
 return s;
}

void push(STACK *s,int data)
{
 if(isFull())
   return;
 s->array[++s->top]=data;  
 printf("\n%d is pushed",s->array[s->top]);
}

int pop(STACK *s)
{
 if(isEmpty())
  return 0;
  printf("\n%d is popped",s->array[s->top]);
 return (s->array[s->top--]);
}

int isEmpty(STACK *s)
{
 return(s->top==-1); 
}

int isFull(STACK *s)
{
 return(s->top==s->capacity-1);
}

void delete(STACK *s)
{
 free(s->array);
 free(s);
}

int main()
{
 STACK *s;
 s=createstack();
 push(s,21);
 push(s,22);
 push(s,24);
 pop(s);
 pop(s);
 pop(s);
 
 delete(s);
 pop(s);
 return 0;
}













