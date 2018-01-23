#ifndef __HEAP_H__
#define __HEAP_H__

struct heap {
    int *data;      // array of data
    int count;      // the count of items
    int capacity;   // the capacity of the heap
    int type;       // min or max
};

struct heap *initHeap(int, int);
int parent(struct heap *, int);
int leftChild(struct heap *, int);
int rightChild(struct heap *, int);
int getMax(struct heap *);
void percolateDown(struct heap *, int);
int deleteMax(struct heap *);
void resizeHeap(struct heap *);
void insert(struct heap *, int);
#endif