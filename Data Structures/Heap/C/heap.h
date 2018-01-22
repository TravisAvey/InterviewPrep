#ifndef __HEAP_H__
#define __HEAP_H__

struct heap {
    int *data;      // array of data
    int count;      // the count of items
    int capacity;   // the capacity of the heap
    int type;       // min or max
};

struct heap *initHeap(int, int);
#endif