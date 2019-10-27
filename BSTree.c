#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *left,*right;
}node;
void insertbst(struct node **p,int v)
{
if(*p==NULL)
{
struct node *newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=v;
newnode->left=NULL;
newnode->right=NULL;
*p=newnode;
}
else if((*p)->data>v)
	insertbst(&(*p)->left,v);
else
	insertbst(&(*p)->right,v);
//printf("%d",(*p)->data);
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
int countnode(struct node *p)
{
if(p==NULL)
return 0;
else
{
int x,y;
x=countnode(p->left);
y=countnode(p->right);
return x+y+1;
}
}
int search(struct node *p,int val)
{
	if(p==NULL)
		return -1;
	while(p!=NULL)
	{
		if((p)->data>val)
			p=p->left;
		else if(p->data<val)
			p=p->right;
		else if(p->data==val)
		{
			printf("The Value is Found and is\t%d\n",p->data);
			return p->data;
		}
	}
	if(p==NULL)
		printf("The value is not present in the TREE\n");
return 0; }
int noLeaf(node *p)
{
	if(p==NULL)
		return 0;
	else if(p->left==NULL&&p->right==NULL)
			return 1;
	else
	{
		int x,y;
		x=noLeaf(p->left);
		y=noLeaf(p->right);
		printf("%d\t",x+y);
		return x+y;
	}
}
int height(node *p)
{
	if(p==NULL)
		return 0;
	else if(p->right==NULL&&p->left==NULL)
		return 0;
	else
	{
		int x,y;
		x=height(p->left);
		y=height(p->right);
		if(x>y)
			return x+1;
		else
			return y+1;
	}
}
int isFull(node *p)
{
	if(p==NULL)
		return 1;
	if(isFull(p->left))
		if(isFull(p->right))
			return 1;
	return 0;
	}

int main()
{
struct node *root=NULL;
insertbst(&root,50);
insertbst(&root,10);
insertbst(&root,40);
insertbst(&root,25);
insertbst(&root,35);
insertbst(&root,47);
insertbst(&root,95);
insertbst(&root,90);
insertbst(&root,100);
insertbst(&root,105);
printf("\ninorder\n");
innode(root);
printf("\n\npreoder\n");
prenode(root);
printf("\n\n\n");
//printf("%d\n",countnode(root));
search(root,35);
printf("\n\n");
printf("\n\n\nres\n%d\n",noLeaf(root));
printf("\n\n%d\n",height(root));
printf("\n\n%d\n",isFull(root));
return 0;
}


