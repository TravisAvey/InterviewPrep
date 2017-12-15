#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    struct Node **linkedList;
    linkedList = (struct Node**) malloc(sizeof(struct Node**));

    pushFront(linkedList, 1);
    pushFront(linkedList, 0);
    pushFront(linkedList, 2);
    pushBack(linkedList, 4);
    pushBack(linkedList, 6);
    insertAt(linkedList, 0, -1);
    
    printf("Length: %i\n", length((*linkedList)));
    printList((*linkedList));

    return EXIT_SUCCESS;
}