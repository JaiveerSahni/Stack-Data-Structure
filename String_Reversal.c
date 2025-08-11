// WAP TO REVERSE A STRING USING STACKS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 30
int top=-1,count=0;
char stack[size];
char output[size]; //STORES THE REVESRED STRING

void push(char temp){
	if(top==size-1){
		printf("Stack Overflow\n");
	}
	else{
		stack[++top]=temp;
	}
}
void pop(){
	if(top==-1){
		printf("Stack Underflow\n");	
	}
	else{
		output[count]=stack[top]; // THE POPPED CHARACTERS OF THE STRING ARE STORED IN THE OUTPUT ARRAY
		top--;
		count++;
	}
}
int main(){
	int i;
	char input[size];
	printf("Enter any string:\n");
	gets(input);
	for(i=0;i<strlen(input);i++){
		push(input[i]);
	}
	for(i=0;i<strlen(input);i++){
		pop();
	}
	printf("\nThe Reversed String: ") ;
	for(i=0;i<strlen(input);i++){
		printf("%c",output[i]);
	}
	return 0;
}
