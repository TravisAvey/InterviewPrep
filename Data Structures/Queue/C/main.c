#include "queue.h"

int main(int argc, char **argv) {
    struct Queue *Q = createQueue();
    if (isEmpty(Q))
        printf("The Queue is empty\n");
    else
        printf("The Queue is not empty\n");
    
    if (isFull(Q))
        printf("The Queue is full\n");
    else
        printf("The Queue is not full\n");
    printf("The size of the Queue is %i\n", size(Q));

    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    printf("Size: %i\n", size(Q));
    enQueue(Q, 5);
    printf("After filling, size: %i\n", size(Q));

    return EXIT_SUCCESS;
}