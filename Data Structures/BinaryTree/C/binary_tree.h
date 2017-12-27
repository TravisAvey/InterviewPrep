#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <stdio.h>
#include <stdlib.h>


struct binaryTree {
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
};

struct binaryTree *insert(struct binaryTree *, int);
struct binaryTree *find(struct binaryTree *, int);
struct binaryTree *findRecursive(struct binaryTree *, int);

void inOrderTraversal(struct binaryTree *);

#endif