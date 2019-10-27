#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node *next;
}Node;
typedef struct queue{
Node *rear,*front;
}queue;


void insert(queue* q, int val){
Node *newnode;
newnode=(Node*)malloc(sizeof(Node));
newnode->next=NULL;
newnode->data=val;
if(q->rear==NULL)
{q->rear=newnode;
q->front=newnode;
}else
{
q->rear->next=newnode;
q->rear=newnode;}
}


int dequeue(queue *q){
int d;
Node *temp;
if(q->front==NULL)                          //first case
d=-1;
else if(q->front->next==NULL)               //last case
{temp=q->front;
	d=q->front->data;
q->front=q->rear=NULL;
free(temp);
}
else if(q->front->next!=NULL){              //in between
d=q->front->data;
temp=q->front;
q->front=q->front->next;
free(temp);
}
return d;
}

void display(queue q){
printf("\nDisplaying all elements in queue:\n");
while(q.front!=NULL){
printf("%d\t",q.front->data);
q.front=q.front->next;}
}



void main(){
queue q;
q.rear=NULL;
q.front=NULL;

insert(&q,10);
insert(&q,20);
insert(&q,30);
display(q);
printf("\nRemoving Element : %d",dequeue(&q));
printf("\nRemoving Element : %d",dequeue(&q));

display(q);
}
