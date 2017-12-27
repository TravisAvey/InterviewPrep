#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(int argc, char **argv) {
    struct binaryTree *bTree;
    bTree = insert(bTree, 2);
    bTree = insert(bTree, 1);
    bTree = insert(bTree, 3);
    bTree = insert(bTree, 4);
    inOrderTraversal(bTree);
    puts("");
    return EXIT_SUCCESS;
}