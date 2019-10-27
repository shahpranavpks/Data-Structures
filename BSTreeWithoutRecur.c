/*For postoder we need to take another stack with 0's and 1's and if left subtree is over make 0 to 1 and go to right ,if right becomes null,
start poping out elements with 1 and stop when u encounter 0*/



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

}


void preorder(node *p)
{
printf("\nPREORDER IS:\n");
node* s[50];
int top=-1;
while(1)
{
while(p!=NULL)
{
s[++top]=p;
printf("%d\t",p->data);
p=p->left;
}
if(top!=-1)
{
p=s[top--];
p=p->right;
}
else break;
}
}


void inorder(node *p)
{
printf("\nINORDER IS:\n");
node* s[50];
int top=-1;
while(1)
{
while(p!=NULL)
{
s[++top]=p;
p=p->left;
}
if(top!=-1)
{
p=s[top--];
printf("%d\t",p->data);
p=p->right;
}
else break;
}
}


void postorder(node *p)
{
printf("\nPOSTORDER IS:\n");
node* s[50];
int top=-1,flag[50];
while(1)
{
while(p!=NULL)
{
s[++top]=p;
flag[top]=0;
p=p->left;
}
if(flag[top]==0)
{
flag[top]=1;
p=s[top];
p=p->right;
}
else{
while(top!=-1 && flag[top]){
printf("%d\t",s[top--]->data);
}}
if(top==-1)
 break;

}
}


int count(node *p)
{
int c=0;
printf("\nPREORDER IS:\n");
node* s[50];
int top=-1;
while(1)
{
while(p!=NULL)
{
s[++top]=p;
printf("%d\t",p->data);
p=p->left;
}
if(top!=-1)
{
c++;
p=s[top--];
p=p->right;
}
else break;
}
return c;
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
preorder(root);
inorder(root);
postorder(root);
printf("\ncount=%d",count(root));
return 0;
}


