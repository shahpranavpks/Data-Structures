#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *left,*right;
}node;


char *createExpTree(node **root,char *prefix)
{
if(*prefix=='\0')
return NULL;
node *newnode=(node*)malloc(sizeof(node));
newnode->left=NULL;
newnode->right=NULL;
*root=newnode;
if(*prefix>='0'&& *prefix<='9')
{
newnode->data=*prefix-48;
return prefix;
}
else
{
newnode->data=*prefix;
char *p=createExpTree(&newnode->left,prefix+1);
p=createExpTree(&newnode->right,p+1);
return p;
}
}



int evalve(node *p)
{
if(p==NULL)
return 0;
if(p->left==NULL && p->right==NULL)
return p->data;
else
{int z=0;
int x=evalve(p->left);
int y=evalve(p->right);

switch(p->data)
{
case '+': z=x+y;break;
case '-': z=x-y;break;
case '*': z=x*y;break;
case '/': z=x/y;break;
case '^': z=x^y;break;
}

return z;
}}

int main()
{
node *root=NULL;
createExpTree(&root,"+*34/72");
int v=evalve(root);
printf("Result is %d",v);
return 0;
}


