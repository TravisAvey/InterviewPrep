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
int find(struct binaryTree *, int);
struct binaryTree *findRecursive(struct binaryTree *, int);
void preOrderTraversal(struct binaryTree *);
void inOrderTraversal(struct binaryTree *);
void postOrderTraversal(struct binaryTree *);
int findMax(struct binaryTree *);
int size(struct binaryTree *);
int treeHeight(struct binaryTree *);

#endif