#include<stdio.h>
typedef struct node{
int data;
struct node *left,*right;
}node;

void insertBt(node **p,int v){
int ch;
printf("Inserting value %d\n",v);
if(*p==NULL){
node *newnode;
newnode=(node*) malloc(sizeof(node));
newnode->data=v;
newnode->left=NULL;
newnode->right=NULL;
*p=newnode;
}
else
{
printf("enter 1 for inserting to left and 2 for right of %d\n",(*p)->data);
scanf("%d",&ch);
if(ch==1)
insertBt(&(*p)->left,v);
else
insertBt(&(*p)->right,v);
}
}

int isComplete(node *p)
{ int x,y;
if(p==NULL)
return 0;
if(p->left==NULL&&p->right==NULL)
return 1;
else
{
x=isComplete(p->left)+1;
y=isComplete(p->right)+1;}
if(x==y &&x!=0)
return x;
else
return 0;
}



//sir's code without pointer
int max2(node *p){
if(p==NULL)
return 0;
else
{
int x=max2(p->left);
int y=max2(p->right);
int z=p->data;
return x>y?(x>z?x:z):(y>z?y:z);
}
}




//using poiter
void maxint(node *p,int *max){
if(p==NULL)
return;
if(p->data>(*max))
*max=p->data;
maxint(p->left,max);	
maxint(p->right,max);
}

int searchBt(node *p,int v){
if(p==NULL)
return 0;
if(p->data==v)
return 1;
else
{
int x=searchBt(p->left,v);
int y=searchBt(p->right,v);
return x||y;
}
}

void prenode(struct node *p)
{
if(p==NULL)
return;
else
{
printf("\n%d\t",p->data);
prenode(p->left);
prenode(p->right);
}
}

void toCopy(node *from,node **to)
{
if(from==NULL){
*to=NULL;
}
else{
*to=(node *)malloc(sizeof(node));
(*to)->data=from->data;
toCopy(from->left,&(*to)->left);
toCopy(from->right,&(*to)->right);
}
}

void innode(struct node *p)
{
if(p==NULL)
return;
else
{
innode(p->left);
printf("\n%d\t",p->data);
innode(p->right);
}
}

void toMirror(node *p)
{
if(p==NULL)
return;
else
{
node *t=p->left;
p->left=p->right;
p->right=t;
toMirror(p->left);
toMirror(p->right);
}
}

int main()
{

int max=0;
node *root=NULL,*root1=NULL;
insertBt(&root,50);
insertBt(&root,10);
insertBt(&root,40);
insertBt(&root,125);
insertBt(&root,35);
insertBt(&root,47);
insertBt(&root,95);
maxint(root,&max);
printf("largest value is %d",max);  //using poiter
printf("\nlargest value is %d",max2(root)); //sir's code without pointer
printf("\nresult of Searching node 10 is %d",searchBt(root,10));
printf("\nresult of Searching node 100 is %d",searchBt(root,100));
printf("\noriginal tree\n");
innode(root);
printf("\nmirror tree\n");
toMirror(root);
innode(root);
toCopy(root,&root1);
printf("\ncopied tree\n");
innode(root1);

}
