#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
int pri;
struct node *next;
}Node;



void insert(Node**p,int v,int pr)
{
Node *newnode,*temp,*prev=NULL;
temp=*p;
while(temp!=NULL){
if(temp->pri>pr)
break;
prev=temp;
temp=temp->next;
}
newnode=(Node*)malloc(sizeof(Node));
newnode->data=v;
newnode->pri=pr;
if(temp==*p){
newnode->next=*p;
*p=newnode;
}
else
{
newnode->next=prev->next;
prev->next=newnode;
}
}


int delete(Node**p){
if(*p==NULL)
return -1;
else{
Node *temp=*p;
*p=(*p)->next;
int v=temp->data;
free(temp);
return v;
}
}

void display(Node *p){
printf("\n");
while(p!=NULL){
printf("%d\t",p->data);
p=p->next;
}
}
void main(){
Node* start=NULL;
insert(&start,0,1);
insert(&start,4,2);
insert(&start,6,3);
insert(&start,7,3);
insert(&start,1,1);
insert(&start,2,1);
insert(&start,5,2);
insert(&start,3,1);
display(start);
delete(&start);
display(start);

return EXIT_SUCCESS;
}