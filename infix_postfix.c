#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int top=-1;
char infix[MAX],postfix[MAX];
char stack[MAX];
void push(char);
char pop();
int isEmpty();
int isFull();
int precedence(char);
void in2post();
 void print();
int main(){
	printf("Enter the Infix expression:");
	gets(infix);
	in2post();
	print();
	return 0;
}
void push(char c){
	if(top==MAX-1){
		printf("Overflow Condition\n");
	}
	else{
		top++;
		stack[top]=c;
	}
}
char pop(){
	 char value;
	if(top==-1){
		printf("\nThe Stack is Empty\n");
	}
	else{
		value=stack[top];
		top--;
	}
	return value;
}
int isEmpty(){
	if(top==-1){
	    return 1;
	}
	else{
		return 0;
	}
}
int isFull(){
	if(top==MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}
int precedence(char symbol){
	switch(symbol){
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
void in2post(){
	int i,j=0;
	char symbol,next;
	for(i=0;i<strlen(infix);i++){
		symbol=infix[i];
	    switch(symbol){
	    	case '(':
	    	   push(symbol);
	    	   break;
	    	case ')':
	    	   while((next=pop())!='(')
	    	     postfix[j++]=next;
	    	    break;
	    	default:
	    		postfix[j++]=symbol;
	    		break;
	    	case '+':
	    	case '-':
	    	case '*':
	    	case '/':
	    	case '^':
	    		while(!isEmpty() && precedence(stack[top])>=precedence(symbol))
	    		 postfix[j++]=pop();
	    		push(symbol);
	    		break;
	    }
	}
	    while(!isEmpty())
	      postfix[j++]=pop();
	    postfix[j]='\0';
	  	    		
}
void print(){
	int i=0;
	printf("The equivalent postfix expression is: ");
	while(postfix[i]!='\0')
	  printf("%c",postfix[i++]);
	printf("\n");
}
	  

	

