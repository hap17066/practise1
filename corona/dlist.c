#include<stdio.h>
#include<stdlib.h>

typedef struct node     
{
 int d;
 struct node *next;
 struct node *prev;
}NODE;

typedef struct list
{
 NODE *head;
 int cnt;
}LIST;

NODE *createnode(int data)
{
 NODE *a;
 a=(NODE *)malloc(sizeof(NODE));
 a->d=data;
 a->next=NULL;
 a->prev=NULL;
 return a;
}

void init(LIST *p)
{
 p->head=NULL;
 p->cnt=0;
}

void addbeg(LIST *p,int data)
{
 NODE *b=p->head;
 NODE *a=createnode(data);
 a->next=b;
 if(b!=NULL)
   b->prev=a;
 p->head=a;
 p->cnt++;
}

void addend(LIST *p,int data)
{
 NODE *a=createnode(data);
 NODE *b=p->head;
 while(b->next!=NULL)
 {
  b=b->next;
 }
 b->next=a;
 a->prev=b;
 p->cnt++;
}

void addmid(LIST *P,int pos,int data)
{
 int i=1;
 NODE *a=createnode(data);
 NODE *b=P->head;
 //NODE *c;
 while(i<pos && b->next!=NULL)
 {
  //c=b;
  b=b->next;
 }
 a->next=b;
 a->prev=b->prev;
 b->prev->next=a;
 b->prev=a;
 P->cnt++;
}

void display(LIST *p)
{
 NODE *a=p->head;
 while(a->next!=NULL)
 {
  printf("%d ",a->d);
  a=a->next;
 }
 
 printf(" %d %d ",a->d,p->cnt);
 printf("\n");
 while(a!=NULL)
 {
  printf("%d",a->d);
  a=a->prev;
 }
}

void delbeg(LIST *p)
{
 NODE *a=p->head;
 p->head=a->next;
 free(a);
 p->cnt--;
}

void delend(LIST *p)
{
 NODE *a=p->head,*b;
 while(a->next!=NULL)
 {
  //b=a;
  a=a->next;
 }
 a->prev->next=NULL;
 free(a);
 p->cnt--;
}

void delmid(LIST *p,int pos)
{
 NODE *a=p->head;
 int i=1;
 while(i<pos)
 {
  //b=a;
  a=a->next;
  i++;
 }
 a->prev->next=a->next;
 a->next->prev=a->prev;
 free(a);
 p->cnt--;
}

void main()
{
 LIST P;
 init(&P);
 int opt,data,pos;

 while(1)
 {
   printf("1:addbeg\n2:addmid\n3:addend\n4:delbeg\n5:delmid\ndelend\n7:display\nopt:");
 scanf("%d",&opt);
  if(opt>7)
    break;
 switch(opt)
 {
  case 1:
  {
   printf("Enter data:");
   scanf("%d",&data);
   addbeg(&P,data);break;
  }
  case 2:
  {
   printf("Enter data:");
   scanf("%d",&data);
   printf("Enter pos:");
   scanf("%d",&pos);
   addmid(&P,pos,data);
  }break;
  case 3:
  {
   printf("Enter data:");
   scanf("%d",&data);
   addend(&P,data);
  }break;
  case 4:
  {
   delbeg(&P);
  }break;
  case 5:
  {
   printf("Enter pos:");
   scanf("%d",&pos);
   delmid(&P,pos);
  }break;
  case 6:
  {
   delend(&P);
  }break;
  case 7:
  {
   display(&P);
  }break;
  
 }
 }
 
}













