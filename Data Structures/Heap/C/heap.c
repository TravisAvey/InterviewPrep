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