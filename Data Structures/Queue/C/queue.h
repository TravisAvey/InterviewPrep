#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define EMPTY -999
#define SIZE 4

struct Queue {
    int front, rear;
    int capacity;
    int *data;
};

struct Queue *createQueue();
int isEmpty(struct Queue *);
int isFull(struct Queue *);
int size(struct Queue *);
void enQueue(struct Queue *, int);
int deQueue(struct Queue *);
void resize(struct Queue *, float);

#endif