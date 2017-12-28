#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define EMPTY INT_MIN
#define SIZE 8

struct Queue {
    int front, rear;
    int capacity;
    int *data;
};

struct Queue *createQueue();
int isEmpty(struct Queue *);
int isFull(struct Queue *);
int size(struct Queue *);

#endif