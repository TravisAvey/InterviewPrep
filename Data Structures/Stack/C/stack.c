#include "stack.h"

struct stack *createStack() {
    struct stack *Stack = malloc(sizeof(struct stack));
    if (!Stack)
        return NULL;
    Stack->capacity = 1;
    Stack->top = -1;
    Stack->data = malloc(Stack->capacity * sizeof(int));
    if (!Stack->data)
        return NULL;
    return Stack;
}

int isEmpty(struct stack *Stack) {
    return (Stack->top == -1);
}

int isFull(struct stack *Stack) {
    return (Stack->top == Stack->capacity-1);
}

void push(struct stack *Stack, int item) {
    if (isFull)
        doubleStack(Stack);
    Stack->data[++Stack->top] = item;
}

int pop(struct stack *Stack) {

}

int top(struct stack *Stack) {

}

void doubleStack(struct stack *Stack) {
    Stack->capacity *= 2;
    Stack->data = realloc(Stack->data, Stack->capacity);
}

void deleteStack(struct stack *Stack) {

}

void printStack(struct stack *Stack) {
    int i;
    for (i=0; i<=Stack->top;i++)
        printf("stack[%i] : %i\n", i, Stack->data[i]);
}