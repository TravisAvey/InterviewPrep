#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int capacity;
    int *data;
};

struct stack *createStack();
int isEmpty(struct stack *);
int isFull(struct stack *);
void push(struct stack *, int);
int pop(struct stack *);
int top(struct stack *);
void doubleStack(struct stack *);
void deleteStack(struct stack *);
void printStack(struct stack *);

#endif