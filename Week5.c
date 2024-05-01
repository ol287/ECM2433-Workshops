#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include for INT_MIN

// Define the structure for a stack node
// structures are the closesnt thing C has to a class
// typedef used to give an alias for an exisiting data type
// ie Node is the alias for the structure
typedef struct Node {
    //each node in a stack must store its data value and a pointer to the next item
    int data;
    //declares a pointer called next that iwll point to the next node
    struct Node* next;
} Node;

// Define the structure for the stack
typedef struct Stack {
    //defines a pointer called top that will point the the top ite
    Node* top;
} Stack;

// Function to create a new node
Node* newNode(int data) {
    //allocate the memory for the new node
    Node *stackNode = (Node*)malloc(sizeof(Node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return !stack->top;
}

// Function to push an item to the stack
void push(Stack* stack, int data) {
    Node* stackNode = newNode(data);
    stackNode->next = stack->top;
    stack->top = stackNode;
    printf("%d pushed to stack\n", data);
}

// Function to pop an item from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    //free memory
    free(temp);
    return popped;
}

// Function to get the top item of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->top->data;
}

// Main function to demonstrate stack operations
int main() {
    Stack stack;
    initStack(&stack);
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(&stack));
    
    return 0;
}
