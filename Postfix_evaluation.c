//WAP TO EVALUATE THE POSTFIX EXPRESSION 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
int top=-1;
char infix[MAX],postfix[MAX];
int stack[MAX];//changed
void push(int);//changed
int pop();//changed
int isEmpty();
int isFull();
int precedence(char);
void in2post();
void print();
int post_eval();
int main(){
	int result;
	printf("Enter the Infix expression:");
	gets(infix);
	in2post();
	print();
	result=post_eval();
	printf("The result obtained after postfix evaluation is: ");
	printf("%d\n",result);
	return 0;
}
void push(int c){  //changed
	if(top==MAX-1){
		printf("Overflow Condition\n");
	}
	else{
		top++;
		stack[top]=c;
	}
}
 int pop(){
	 int value; //changed
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
int post_eval()	  {
	int i;
	int a,b;
	for(i=0;i<strlen(postfix);i++){
		if((postfix[i])>='0' && (postfix[i])<='9'){
			push(postfix[i]-'0');
		}
		else{
			a=pop();
			b=pop();
			switch(postfix[i]){
				case '+':
					push(b+a);
					break;
			    case '-':
					push(b-a);
					break;
				case '*':
					push(b*a);
					break;
				case '/':
					push(b/a);
					break;
				case '^':
					push(pow(b,a));
					break;
				
					
			}
		}
	}
	return pop();
}

	

