#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct heap *initHeap(int capacity, int type) {
    struct heap *h = (struct heap *) malloc(sizeof(struct heap));

    if (h == NULL) {
        fprintf(stderr, "There was a problem initializing the heap\n");
        return NULL;
    }

    h->type = type;
    h->count = 0;
    h->capacity = capacity;

    h->data = (int *) malloc(sizeof(int) * h->capacity);

    if (h->data == NULL) {
        fprintf(stderr, "There was a problem initializing the heap array\n");
        return NULL;
    }
    return h;
}

/*
    This method returns the parent of the
    ith node.
    The parent is found at (i - 1) / 2
*/
int parent(struct heap *h, int i) {
    if (i <= 0 || i >= h->count)
        return -1;
    return (i-1) / 2;
}

int leftChild(struct heap *h, int i) {
    int left = 2 * i + 1;

    if (left >= h->count)
        return -1;
    return left;
}

int rightChild(struct heap *h, int i) {
    int right = 2 * i + 2;
    if (right >= h->count)
        return -1;
    return right;
}

/*
    This method return the maximum of the heap
    which is always at the root
*/
int getMax(struct heap *h) {
    if (h->count == 0)
        return -1;
    return h->data[0];
}

/*
    This method handles satisfying the heap property
    by ensuring the root has the max of the heap

    This subroutine is used after inserting a new node.

    This is done by finding the max of each of its children
    with the current and swap until the heap property is
    satisfied at every node
*/
void percolateDown(struct heap *h, int i) {
    int left, right, max, temp;
    left = leftChild(h, i);
    right = rightChild(h, i);

    if (left != -1 && h->data[left] > h->data[i])
        max = left;
    else
        max = i;
    if (right != -1 && h->data[right] > h->data[max])
        max = right;
    
    if (max != i) {
        temp = h->data[i];
        h->data[i] = h->data[max];
        h->data[max] = temp;
    }

    percolateDown(h, max);
}

int deleteMax(struct heap *h) {
    if (h->count == 0)
        return -1;
    int data;
    data = h->data[0];

    h->data[0] = h->data[h->count-1];
    h->count--;
    percolateDown(h, 0);
    return data;
}

void resizeHeap(struct heap *h) {
    int *old = h->data;
    h->data = (int *) malloc(sizeof(int) * h->capacity * 2);

    if (h->data == NULL) {
        fprintf(stderr, "There was a problem reallocating memory in resizing the heap\n");
        return;
    }

    for (int i=0; i<h->capacity; i++)
        h->data[i] = old[i];
    h->capacity *= 2;
    
    free(old);
}


void insert(struct heap *h, int data) {
    if (h->count == h->capacity)
        resizeHeap(h);
    int i;
    h->count++;
    i = h->count-1;
    while (i >= 0 && data > h->data[(i-1)/2]) {
        h->data[i] = h->data[(i-1)/2];
        i = (i-1) / 2;
    }
    h->data[i] = data;
}