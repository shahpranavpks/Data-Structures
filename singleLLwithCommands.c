#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;

}Node;

void add(Node **p,int v){
	Node *temp,*newnode;
	newnode=(Node*)malloc(sizeof(Node));
	newnode->data=v;
	if(*p==NULL){
		*p=newnode;
	}
	else{ temp=*p;
	    while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
}
}
void display(Node *p){
	while(p!=NULL){
printf("\n%d",p->data);
p=p->next;
}
}
void reverse(Node**p){
Node *prev,*temp;
prev=NULL;
while((*p)!=NULL){
temp=(*p)->next;
(*p)->next=prev;
prev=*p;
*p=temp;
}
*p=prev;
}

void copy(Node *p,Node*q){
Node *temp=p;
Node *temp1=q;
for(temp=p;temp!=NULL;temp=temp->next){
temp1->data=temp->data;
temp1=temp1->next;
}
}

void concat(Node *p,Node*q){
Node *temp=p;
Node *temp1=q;
for(temp=p;temp!=NULL;temp=temp->next){
add(&temp1,temp->data);
}
}

int count(Node* p){
int counter=0;
while(p!=NULL){
p=p->next;
counter++;
}
return counter;
}

int main(void) {
Node *first=NULL;
Node *second=NULL;
		
        add(&first,10);
	add(&first,20);
	add(&first,30);
	add(&first,40);
	display(first);
        add(&second,50);
	add(&second,60);
	add(&second,70);
	add(&second,80);
        printf("\n");
	display(second);

       copy(first,second);
printf("\n");
	display(first);
	display(second);
       concat(first,second);
      printf("\nConcating 1 in 2\n");
display(second);
printf("\nreverse of 1\n");
reverse(&first);
printf("\n");
display(first);
reverse(&second);
printf("\n");
display(second);
printf("\ncount of 2=%d",count(second));
printf("\ncount of 1=%d",count(first));
	return EXIT_SUCCESS;
}

