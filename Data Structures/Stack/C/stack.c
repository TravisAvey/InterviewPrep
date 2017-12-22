#include "stack.h"
/*
    This method initializes a new stack
*/
struct stack *createStack() {
    // allocate the memory for the stack
    struct stack *Stack = malloc(sizeof(struct stack));
    // if the memory location is null
    if (!Stack) {
        fprintf(stderr, "Error creating the stack\n");
        return NULL;
    }
    // initialize the capacity to the size
    Stack->capacity = SIZE;
    // set the top to -1 (-1 means empty)
    Stack->top = -1;
    // allocate the memory for the array
    Stack->data = malloc(Stack->capacity * sizeof(int));
    // if memory location for data is null
    if (!Stack->data) {
        fprintf(stderr, "Error creating data arrary\n");
        return NULL;
    }
    // return the stack
    return Stack;
}

// Returns 0 if stack is empty, 1 if not empty
int isEmpty(struct stack *Stack) {
    return (Stack->top == -1);
}

// returns 0 if stack is full, 1 if not full
int isFull(struct stack *Stack) {
    return (Stack->top == Stack->capacity-1);
}

// pushes a new item on the stack
void push(struct stack *Stack, int item) {
    // if the stack is full
    if (isFull(Stack)) {
        // call subroutine to double size of stack
        resizeStack(Stack, DOUBLE);
    }
    // add item to the top of the stack
    Stack->data[++Stack->top] = item;
}

// removes top item from the stack
int pop(struct stack *Stack) {
    // if the top position is less than half
    if (Stack->top < (Stack->capacity / 2))
        // resize stack to 1/2 the size
        resizeStack(Stack, HALF);
    // remove the top and return it
    return Stack->data[Stack->top--];
}

// returns the top item from the stack
int top(struct stack *Stack) {
    return Stack->data[Stack->top];
}

// this method doubles the size of the stack
void resizeStack(struct stack *Stack, enum resize r) {
    // if caller wants to double
    if (r ==  DOUBLE)
        // resize the capacity by 2
        Stack->capacity *= 2;
    // if caller wants to half the stac
    else if (r == HALF)
        // resuze the capacity by half
        Stack->capacity /= 2;
    // reallocate the memory for the new size
    Stack->data = realloc(Stack->data, Stack->capacity);
}

// this method deletes the stack
void deleteStack(struct stack *Stack) {
    // if the stack location is not null
    if (Stack) {
        // if the data array is not null
        if (Stack->data)
            // free the memory for the array
            free(Stack->data);
        // free the memory location of the stack
        free(Stack);
    }
}

// this method prints out each item in the stack
void printStack(struct stack *Stack) {
    int i;
    // print out from top to bottom
    for (i=Stack->top; i>=0; i--)
        printf("stack[%i] : %i\n", i, Stack->data[i]);
}