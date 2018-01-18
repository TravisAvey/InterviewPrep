#include "queue.h"

/*
    This method handles the create of the Queue
*/
struct Queue *createQueue() {
    // allocate memory for the queue
    struct Queue *queue = malloc(sizeof(struct Queue));

    // if queue is null
    if (!queue) {
        // output error to user
        fprintf(stderr, "There was a problem initializing the Queue\n");
        // return null
        return NULL;
    }
    // set the capacity
    queue->capacity = SIZE;
    // init the front/rear to empty
    queue->front = queue->rear = EMPTY;
    // allocate memory for the array
    queue->data = malloc(queue->capacity * sizeof(int));
    // if the array is null
    if (!queue->data) {
        // output error to user
        fprintf(stderr, "There was a problem initializing the array for the Queue\n");
        // return null
        return NULL;
    }
    // return the queue
    return queue;
}

/* This method returns 1 if empty, 0 if not */
int isEmpty(struct Queue *Q) {
    return (Q->front == EMPTY);
}

/* This method returns 1 if full, 0 if not */
int isFull(struct Queue *Q) {
    // if the rear mod capacity is the same as the front
    // then this queue is full
    return ((Q->rear+1) % Q->capacity == Q->front);
}

/* This method returns the size of the queue */
int size(struct Queue *Q) {
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}

/* This method adds data to the queue */
void enQueue(struct Queue *Q, int data) {
    // if this queue is full
    if (isFull(Q))
        // resize by 2
        resize(Q, 2.0f);
    // change the rear based on the end mod capcity
    Q->rear = (Q->rear+1) % Q->capacity;
    // set the data to the rear of the queue
    Q->data[Q->rear] = data;

    // if front is -1
    if (Q->front == -1)
        // front and rear are the same point
        Q->front = Q->rear;
}

/* This method handles removing the first
    item in the queue */
int deQueue(struct Queue *Q) {
    // init data to 0
    int data = 0;
    // if this queue is empty
    if (isEmpty(Q))
        // return the data
        return data;
    else {
        // check if the size is less than half of capacity
        if (size(Q) < Q->capacity / 2)
            // resize by half
            resize(Q, 0.5f);
        // grab the data from the front
        data = Q->data[Q->front];
        // if one item in queue
        if (Q->front == Q->rear)
            // set front to rear - 1 
            Q->front = Q->rear - 1;
        else
            // set the front
            Q->front = (Q->front+1) % Q->capacity;
    }
    // return the data
    return data;
}

/* This method handles resizing the queue */
void resize(struct Queue *Q, float factor) {
    // get the capacity
    int size = Q->capacity;
    // change the capacity by the factor
    Q->capacity = (int) (size * factor);
    // reallocate the memory
    Q->data = realloc(Q->data, Q->capacity);
    // if the array is null
    if (!Q->data) {
        // output error message to user
        fprintf(stderr, "There was an error reallocating memory\n");
        // and return
        return;
    }
    // as long as the front is before the rear of the queue
    if (Q->front > Q->rear) {
        // loop over the array to front
        int i;
        for (i=0; i<Q->front; i++)
            // copy over
            Q->data[i+size] = Q->data[i];
        // set th rear
        Q->rear = Q->rear + size;
    }
}
