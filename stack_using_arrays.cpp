#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(int data){
	if(top==MAX-1){
		printf("Overflow Condition\n");
	}
	else{
		top++;
		stack[top]=data;
	}
}
int pop(){
	int value;
	if(top==-1){
		printf("\nThe Stack is Empty\n");
	}
	else{
		value=stack[top];
		top--;
	}
	return value;
}
void print(){
	int i;
	for(i=0;i<=top;i++){
		printf("%d ",stack[i]);
	}
}
 void peek(){
	printf("\nThe topmost element in the stack is %d\n",stack[top]);
}
int main(){
	int data;
	push(3);
	push(4);
	push(5);
	push(6);
	print();
	peek();
	data=pop();
	printf("\nThe Popped Value is %d\n",data);
	data=pop();
	printf("\nThe Popped Value is %d\n",data);
	print();
	peek();
}

