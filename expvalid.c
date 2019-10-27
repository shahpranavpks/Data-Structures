

#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct stack
{
	int a[size];
	int top;

}stk;
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
int main(void) {
	stk s;
	int v;
	int i=0,j=0;

	char c[20];
	s.top=-1;
	printf("enter string");
	gets(c);
	for(i=0;c[i];i++){
		if(c[i]=='(' ||c[i]=='['||c[i]=='{' )
			push(&s,c[i]);
		else if(c[i]==')'){
			if((v=peek(&s))=='(')
		if( (v=pop(&s))==-1){
				break;
			}}
		else if(c[i]==']'){
					if((v=peek(&s))=='[')
				if( (v=pop(&s))==-1){
						break;
					}}

		else if(c[i]=='}'){
					if((v=peek(&s))=='{')
				if( (v=pop(&s))==-1){
						break;
					}}

	}
    if(isempty(&s) && c[i]=='\0')
    	printf("\n valid");
    else
    	printf("\nnot valid ");


	return EXIT_SUCCESS;
}

/*better method
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
break;}}
if(isempty(&s)&&f!=0){
printf("balanced");
}else
printf("unbalanced");

	}
