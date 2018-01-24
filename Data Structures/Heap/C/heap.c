#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*
    This method handles initializing the new heap
*/
struct heap *initHeap(int capacity, int type) {
    // allocate memory for the heap
    struct heap *h = (struct heap *) malloc(sizeof(struct heap));
    // if null, output message and exit method
    if (h == NULL) {
        fprintf(stderr, "There was a problem initializing the heap\n");
        return NULL;
    }
    // init the Heap ADT
    h->type = type;
    h->count = 0;
    h->capacity = capacity;
    // allocate memory for array
    h->data = (int *) malloc(sizeof(int) * h->capacity);
    // if null, output message and exit
    if (h->data == NULL) {
        fprintf(stderr, "There was a problem initializing the heap array\n");
        return NULL;
    }
    // return the newly created heap
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

/*
    This method returns the location
    of the left child (from parent i)
*/
int leftChild(struct heap *h, int i) {
    // left is as follows:
    int left = 2 * i + 1;
    // if left is greater than count
    if (left >= h->count)
        // it's not right, return -1
        return -1;
    // return position
    return left;
}

/*
    This method returns the location
    of the right child (of parent i)
*/
int rightChild(struct heap *h, int i) {
    // the right is as follows:
    int right = 2 * i + 2;
    // if greater, error return -1
    if (right >= h->count)
        return -1;
    // return right
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
    // get the left and right child
    left = leftChild(h, i);
    right = rightChild(h, i);
    // check left
    if (left != -1 && h->data[left] > h->data[i])
        // set left as max
        max = left;
    else
        // else max is i
        max = i;
    // check right
    if (right != -1 && h->data[right] > h->data[max])
        // set max as right
        max = right;
    
    // if max isn't i
    if (max != i) {
        // swap data[i] and data[max]
        temp = h->data[i];
        h->data[i] = h->data[max];
        h->data[max] = temp;

        // bug here, should only be called
        // if max is not equal to i
        // was causing segmentaion fault
        percolateDown(h, max);
    }
}

/*
    This method delete's the max (root)
    from the heap and returns it
*/
int deleteMax(struct heap *h) {
    // if the count is 0, nothing to delete
    if (h->count == 0)
        // return -1
        return -1;
    // get the data from the root
    int data;
    data = h->data[0];
    // set the root to the most bottom child
    h->data[0] = h->data[h->count-1];
    // decrement count
    h->count--;
    // percolate down to re-heapify the heap
    percolateDown(h, 0);
    // return the deleted max (root)
    return data;
}

/*
    This method handles resizing the
    heap by 2 if while inserting we
    reach the max
*/
void resizeHeap(struct heap *h) {
    // create copy of data array
    int *old = h->data;
    // reallocate enough memory space for X2 the capacity
    h->data = (int *) malloc(sizeof(int) * h->capacity * 2);
    // if null, memory error
    if (h->data == NULL) {
        // output message and exit method
        fprintf(stderr, "There was a problem reallocating memory in resizing the heap\n");
        return;
    }
    // loop over and copy into new reallocated array
    for (int i=0; i<h->capacity; i++)
        h->data[i] = old[i];
    // set capacity
    h->capacity *= 2;
    
}

/*
    This method handles inserting
    a new node into the heap
*/
void insert(struct heap *h, int data) {
    // if we are at capacity, resize
    if (h->count == h->capacity)
        resizeHeap(h);
    
    int i;
    // increment the count
    h->count++;
    // get the count
    i = h->count-1;
    // keep looping while i is less than 0
    // and the data is greater than the parent node
    // in essence, the percolates the data up into 
    // the correct position of the heap
    while (i > 0 && data > h->data[(i-1)/2]) {
        // set the data location to parent
        h->data[i] = h->data[(i-1)/2];
        // move to parent
        i = (i-1) / 2;
    }
    // when fall out of while loop
    // we are at the right place 
    // to insert the data
    h->data[i] = data;
}