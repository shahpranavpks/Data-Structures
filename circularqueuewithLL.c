#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
int data;
struct Node *next;
}Node;


void insert(Node** p,int val){
Node *newnode,*temp;
newnode=(Node*)malloc(sizeof(Node));

newnode->data=val;
if(*p==NULL)
{*p=newnode;
newnode->next=newnode;
}
else
{
//temp=(*p)->next;
newnode->next=(*p)->next;
(*p)->next=newnode;
(*p)=newnode;
}
}


int dequeue(Node **p){
int d;
Node *temp;
if(*p==NULL)                          //first case
d=-1;
else if(*p==(*p)->next)               //last case
{temp=(*p)->next;
d=(*p)->next->data;
*p=NULL;
free(temp);
}
else {                                //in between
temp=(*p)->next;
d=(*p)->next->data;
(*p)->next=(*p)->next->next;
free(temp);
}
return d;
}

void display(Node *p){
Node *temp;

if(p==NULL)
printf("\nEmpty Queue");
else{
temp=p->next;
printf("\nDisplaying all elements in queue:\n");
do{
printf("%d\t",temp->data);
temp=temp->next;
}
while(temp!=p->next);
}}



void main(){
Node *last;
last=NULL;

insert(&last,10);
insert(&last,20);
insert(&last,30);
insert(&last,30);
display(last);
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
printf("\nRemoving Element : %d",dequeue(&last));
display(last);
}
