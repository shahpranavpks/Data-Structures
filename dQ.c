#include<stdlib.h>
#include<stdio.h>
#define size 5
typedef struct deque{
int a[size];
int rear,front;
int count;
}dq;

int insert_f(dq *p, int v)
{
if(p->count==size)
return 0;
else{
p->front=(p->front+1)%size;
p->a[p->front]=v;
p->count++;
return 1;
}
}


int insert_l(dq *p,int v){
if(p->count==size)
return 0;
else{
p->rear=p->rear-1;
if(p->rear==-1)
p->rear=0;
p->a[p->rear]=v;
++p->count;
return 1;
}
}

void init(dq* p){
p->rear=size;
p->front=-1;
p->count=0;
}


int delete_f(dq *p){
if(p->count==0)
return -1;
else{
if(p->front==-1)
p->front=size-1;
int v=p->a[p->front--];

--p->count;
return v;
}
}


int delete_l(dq *p){
if(p->count==0)
return -1;
else{
if(p->rear==size)
p->rear=0;
int v=p->a[p->rear];
p->rear=p->rear+1;
--p->count;
return v;
}
}


void main(){
dq x;
init(&x);
insert_f(&x,10);
insert_f(&x,20);
insert_f(&x,30);
insert_l(&x,21);
insert_l(&x,31);
while(x.count!=0){
//printf("\n%d",delete_f(&x));
printf("\n%d",delete_l(&x));
}
}


