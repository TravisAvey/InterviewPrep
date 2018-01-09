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

void enQueue(struct Queue *Q, int data) {
    if (isFull(Q))
        resize(Q);
    Q->rear = (Q->rear+1) % Q->capacity;
    Q->data[Q->rear] = data;

    if (Q->front == -1)
        Q->front = Q->rear;
}

int deQueue(struct Queue *Q) {
    int data = 0;
    if (isEmpty(Q))
        return data;
    else {
        data = Q->data[Q->front];
        if (Q->front == Q->rear)
            Q->front = Q->rear - 1;
        else
            Q->front = (Q->front+1) % Q->capacity;
    }
    return data;
}

void resize(struct Queue *Q) {
    int size = Q->capacity;
    Q->capacity = size * 2;
    Q->data = realloc(Q->data, Q->capacity);
    if (!Q->data) {
        fprintf(stderr, "There was an error reallocating memory\n");
        return;
    }
    if (Q->front > Q->rear) {
        int i;
        for (i=0; i<Q->front; i++)
            Q->data[i+size] = Q->data[i];
        Q->rear = Q->rear + size;
    }
}