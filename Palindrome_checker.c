//WAP TO CHECK WHETHER A STRING IS PALINDROME OR NOT USING STACKS
//PALINDROME CHECKER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int top=-1;
char stack[MAX];
void push(char);
char pop();
int isEmpty();
int isFull();
void palindrome_check(char*);

int main(){
	char s[100];
	printf("Enter any valid string: ");
	scanf("%s",s);

	palindrome_check(s);
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
void palindrome_check(char* s){
int i=0,length=strlen(s);
for(i=0;i<length/2;i++){
	push(s[i]);
}
if(length%2!=0)
  i++;
while(s[i]!='\0'){
	if(s[i]!=pop())
	{
	printf("Not a Palindrome");
	exit(1);
}
i++;
}
printf("Palindrome.\n");

}



