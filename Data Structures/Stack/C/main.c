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
    push(Stack, 6);
    printStack(Stack);
    printf("Top: %i\n", top(Stack));
    printf("Pop: %i\n", pop(Stack));
    printf("Top: %i\n", top(Stack));
    deleteStack(Stack);

    return EXIT_SUCCESS;
}
