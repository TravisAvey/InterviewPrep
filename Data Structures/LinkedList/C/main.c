#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    struct Node **linkedList;
    linkedList = (struct Node**) malloc(sizeof(struct Node**));
    
    printf("popFront : %i\n", popFront(linkedList));
    pushFront(linkedList, 1);
    pushFront(linkedList, 0);
    pushFront(linkedList, 2);
    pushBack(linkedList, 4);
    pushBack(linkedList, 6);
    insertAt(linkedList, 0, -1);

    printf("Length: %i\n", length((*linkedList)));
    printList((*linkedList));
    printf("popFront : %i\n", popFront(linkedList));
    printf("popFront : %i\n", popFront(linkedList));
    printf("popBack : %i\n", popBack(linkedList));
    printList((*linkedList));
    return EXIT_SUCCESS;
}
