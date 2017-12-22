#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    struct stack *Stack = createStack();
    printf("stack size: %i\n", Stack->capacity);
    if (isEmpty(Stack))
        printf("Stack is empty\n");
    if (!isFull(Stack))
        printf("Stack is not full\n");

    push(Stack, 5);
    printf("Size: %i\n", Stack->capacity);
    push(Stack, 6);
    printf("Size: %i\n", Stack->capacity);
    push(Stack, 10);
    printf("Size: %i\n", Stack->capacity);
    push(Stack, 11);
    printf("Size: %i\n", Stack->capacity);
    push(Stack, 15);
    printf("Size: %i\n", Stack->capacity);
    printStack(Stack);
    printf("Top: %i\n", top(Stack));
    printf("Pop: %i\n", pop(Stack));
    printf("Top: %i\n", top(Stack));
    printf("Pop: %i\n", pop(Stack));
    printf("Pop: %i\n", pop(Stack));
    printf("Pop: %i\n", pop(Stack));
    printStack(Stack);
    printf("Size: %i\n", Stack->capacity);
    deleteStack(Stack);

    return EXIT_SUCCESS;
}
