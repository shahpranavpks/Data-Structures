#include<stdlib.h>
#include<stdio.h>
#define size 100
typedef struct heap
{
int pri[size];
int data[size];
int index;
}Heap;

int insert(Heap*p,int v,int pri)
{
int i;
if(p->index==size-1)
return 0;
else{
for(i=++p->index;i>0&&p->pri[(i-1)/2]>pri;i=(i-1)/2)
{
p->pri[i]=p->pri[(i-1)/2];
p->data[i]=p->data[(i-1)/2];
}
p->pri[i]=pri;
p->data[i]=v;

}
}

void display(Heap p)
{int i;

for(i=0;i<=p.index;i++){
printf("%d\t",p.data[i]);
}

}

int delMinHeap(Heap*p){
int val,pri,data,i;
if(p->index==-1)
return -1;
else{
val=p->data[0];
pri=p->pri[p->index];
data=p->data[p->index--];
for(i=1;i<=p->index;i=2*i+1){
if((i+1)<=p->index && p->pri[i]>p->pri[i+1])
i++;
if(pri>p->pri[i])
{
p->pri[(i-1)/2]=p->pri[i];
p->data[(i-1)/2]=p->data[i];
}else
break;
}
p->pri[(i-1)/2]=pri;
p->data[(i-1)/2]=data;
return val;
}
}



void main(){
Heap s;
s.index=-1;
insert(&s,5,5);
insert(&s,7,7);
insert(&s,6,6);
insert(&s,3,3);
insert(&s,4,4);
insert(&s,1,1);
display(s);
delete(&s);
display(s);
return EXIT_SUCCESS;
}