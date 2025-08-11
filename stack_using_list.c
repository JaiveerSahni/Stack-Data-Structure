// IMPLEMENTING STACK USING LINKED LISTS
#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node
struct node {
    int info;
    struct node *next;
} *top;  // Global variable for the top of the stack

void create();
void push(int data);
void pop();
void display();
void empty();
int topelement();

int main() {
    int no, ch, e;
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Top");
    printf("\n 4 - Empty");
    printf("\n 5 - Exit");
    printf("\n 6 - Display");
    create();
    
    while (1) {
        printf("\n Enter choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &no);
            push(no);
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL)
                printf("No elements in stack");
            else {
                e = topelement();
                printf("\n Top element: %d", e);
            }
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        default:
            printf("Wrong choice, please enter correct choice");
            break;
        }
    }
    return 0;
}

void create() {
    top = NULL;  // Initialize top to NULL
}

// Push operation
void push(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newnode->info = data;
    newnode->next = top;
    top = newnode;
    
    printf("Element %d pushed onto the stack\n", data);
}

// Pop operation
void pop() {
    if (top == NULL) {
        printf("\nTrying to delete from an empty stack\n");
        return;
    }
    
    struct node *temp = top;
    printf("\nThe popped element is: %d\n", top->info);
    
    top = top->next;  // Move top to the next node
    free(temp);  // Free the memory of the old top node
}

// Display stack contents
void display() {
    struct node *temp = top;
    
    if (top == NULL) {
        printf("The stack is empty\n");
        return;
    }
    
    printf("The elements in the stack are: ");
    while (temp != NULL) {
        printf("%d --> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Get the top element without removing it
int topelement() {
    if (top != NULL) {
        return top->info;
    } else {
        printf("Stack is empty\n");
        return -1;  // Return -1 to indicate an error (stack empty)
    }
}

// Check if the stack is empty
void empty() {
    if (top == NULL) {
        printf("\nThe stack is empty\n");
    } else {
        printf("\nThe stack is not empty\n");
    }
}

