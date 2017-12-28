#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(int argc, char **argv) {
    struct binaryTree *bTree;
    /*
                 7
              /    \ 
             6      8
           /  \    / \
          5   4   9   10
    */
    bTree = insert(bTree, 7);
    bTree = insert(bTree, 6);
    bTree = insert(bTree, 8);
    bTree = insert(bTree, 9);
    bTree = insert(bTree, 5);
    bTree = insert(bTree, 4);
    bTree = insert(bTree, 10);

    preOrderTraversal(bTree);
    puts("");
    inOrderTraversal(bTree);
    puts("");
    postOrderTraversal(bTree);
    puts("");
    return EXIT_SUCCESS;
}