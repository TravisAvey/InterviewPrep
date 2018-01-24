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
        printf("Inserting 8\n");
        insert(H, 8);
        printf("Inserting 10\n");
        insert(H, 10);
        insert(H, 24);
        insert(H, 2);
        insert(H, 38);
        printf("getMax: %i\n", getMax(H));
        printf("deleteMax: %i\n", deleteMax(H));
        printf("deleteMax: %i\n", deleteMax(H));
        printf("deleteMax: %i\n", deleteMax(H));
        printf("deleteMax: %i\n", deleteMax(H));
        printf("getMax: %i\n", getMax(H));
    }

    return EXIT_SUCCESS;
}