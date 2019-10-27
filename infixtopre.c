#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define size 50
typedef struct stack
{
	int a[size];
	int top;

}stk;
int preced(char c){
switch(c)
{
case '^':return 5;
case '*':
case'/':
case'%': return 4;
case '+':
case'-':return 3;
case '(':
case ')':return 2;
}return 0;
}
int push(stk *p,char val)
{
	if(p->top==size-1)
		return 0;
	else
	{
		p->a[++p->top]=val;
		return 1;
	}
}
char peek(stk *p){
	if(p->top==-1)
			return -1;
		else
		{
			return p->a[p->top];
		}
}
int pop(stk *p)
{
	if(p->top==-1)
		return -1;
	else
	{
		return p->a[p->top--];
	}
}
int isempty(stk *p)
{
	return p->top==-1;
}


void infixtopre(char *infix,char *post){

	int n, j=0,i;
	stk s;
	s.top=-1;
	n=strlen(infix);
	for(i=n-1;i>=0;i--){
		if(infix[i]>='a'&& infix[i]<='z')
			post[j++]=infix[i];
		else if(infix[i]=='^'&&peek(&s)=='^')
		post[j++]='^';
		else{
			if(isempty(&s)||infix[i]==')'||preced(infix[i])>=preced(peek(&s)))
				push(&s,infix[i]);
			else if(infix[i]=='('){
				while(peek(&s)!=')')
					post[j++]=pop(&s);
				pop(&s);
			}else
			{
				while(!isempty(&s)&& preced(infix[i])<=preced(peek(&s)))
					post[j++]=pop(&s);
				push(&s,infix[i]);
			}
		}
	}
	while(!isempty(&s))
		post[j++]=pop(&s);
	post[j]=0;

}

int balanced(char c[]){
int i,f;
stk s;
s.top=-1;

	for(i=0;c[i];i++){

		if(c[i]=='(')
                       push(&s,')');
		else	if(c[i]=='[')
                        push(&s,']');
          else if( c[i]=='{')
                       push(&s,'}');

	else if(c[i]=='}'||c[i]==')'||c[i]==']')
{
if(c[i]!=pop(&s)){
f=0;
break;}}}
if(isempty(&s)&&f!=0){
return 1;
}else
return 0;

}

int main(void) {
	stk s;
	int v,f=1;
	int i=0,j=0;
char post[20];
	char c[20];
	s.top=-1;
	printf("enter string");
	gets(c);
if(balanced(c)){
    	infixtopre(&c,&post);

for(i=strlen(post)-1;post[i]!=0;i--)
    printf("%c",post[i]);
}else
printf("Invalid");
	return EXIT_SUCCESS;
}

