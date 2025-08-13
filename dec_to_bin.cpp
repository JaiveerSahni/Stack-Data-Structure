// WAP TO CONVERT DECIMAL TO BINARY
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
	int value=-1;
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
	for(i=top;i>=0;i--){
		printf("%d ",stack[i]);
	}
}
void dec2bin(int n){
	while(n!=0){
		push(n%2);
		n=n/2;
	}

}
int main(){
	int n;
	printf("Enter any number:");
	scanf("%d",&n);
	dec2bin(n);
	print();
	return 0;
}

