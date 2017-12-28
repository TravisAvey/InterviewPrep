#include "queue.h"

struct Queue *createQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));

    if (!queue) {
        fprintf(stderr, "There was a problem initializing the Queue\n");
        return NULL;
    }
    queue->capacity = SIZE;
    queue->front = queue->rear = EMPTY;
    queue->data = malloc(queue->capacity * sizeof(int));
    if (!queue->data) {
        fprintf(stderr, "There was a problem initializing the array for the Queue\n");
        return NULL;
    }
    return queue;
}

int isEmpty(struct Queue *Q) {
    return (Q->front == EMPTY);
}

int isFull(struct Queue *Q) {
    return ((Q->rear+1) % Q->capacity == Q->front);
}

int size(struct Queue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}