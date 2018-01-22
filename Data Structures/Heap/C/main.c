#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(int argc, char **argv) {

    struct heap *H = initHeap(8, 1);
    if (H == NULL) {
        printf("Error with the heap\nExiting...\n");
        return EXIT_FAILURE;
    } else {
        printf("All systems OK\nContinue with the Heap\n");
    }

    return EXIT_SUCCESS;
}