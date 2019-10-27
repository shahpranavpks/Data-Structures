#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *next,*prev;
}Node;

typedef struct queue{
Node *front,*rear;
}Q;

int insert_f(Q *p,int v){
Node *newnode;
newnode=(Node*)malloc(sizeof(Node));
newnode->data=v;
newnode->prev=NULL;
newnode->next=NULL;
if(p->front==NULL)
{p->front=newnode;
p->rear=newnode;
}
else{
p->front->prev=newnode;
newnode->next=p->front;
p->front=newnode;
}
}

int insert_l(Q *p,int v){
Node *newnode;
newnode=(Node*)malloc(sizeof(Node));
newnode->data=v;
newnode->next=NULL;
newnode->prev=NULL;
if(p->front==NULL)
{p->front=newnode;
p->rear=newnode;
}
else{
p->rear->next=newnode;
newnode->prev=p->rear;
p->rear=newnode;
}
}


int delete_f(Q *p){
int v;
Node *temp;
temp=p->front;
if(p->front==NULL)
return -1;
else{
v=p->front->data;
p->front=p->front->next;
free (temp);
return v;
}
}


int delete_l(Q *p){
int v;
Node *temp;
temp=p->rear;
if(p->front==NULL)
return -1;
else{
v=p->rear->data;
p->rear=p->rear->prev;
free (temp);
return v; 
}
}


void main(){
Q x;
x.front=NULL;
x.rear=NULL;
insert_f(&x,10);
insert_f(&x,20);
insert_f(&x,30);
insert_l(&x,21);
insert_l(&x,31);
/*printf("\n%d",delete_f(&x));
printf("\n%d",delete_f(&x));
printf("\n%d",delete_f(&x));
printf("\n%d",delete_f(&x));
printf("\n%d",delete_f(&x));*/
printf("\n%d",delete_l(&x));
printf("\n%d",delete_l(&x));
printf("\n%d",delete_l(&x));
printf("\n%d",delete_l(&x));
printf("\n%d",delete_l(&x));
}

