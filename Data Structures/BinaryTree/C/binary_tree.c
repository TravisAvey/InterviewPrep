#include "binary_tree.h"

struct binaryTree *insert(struct binaryTree *root, int data) {
    if (root == NULL) {
        root = (struct binaryTree *) malloc((sizeof (struct binaryTree)));

        if (root == NULL) {
            fprintf(stderr, "Memory Error constructing the root of the tree\n");
            return NULL;
        } else {
            root->data = data;
            root->left = root->right = NULL;
        }
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
    }

    return root;
}

struct binaryTree *find(struct binaryTree *root, int data) {
    if (root == NULL){
        printf("Tree is empty\n");
        return NULL;
    }

    while (root) {
        if (data == root->data)
            return root;
        else if (data > root->data)
            root = root->right;
        else
            root = root->left;
    }

    return NULL;
}

struct binaryTree *findRecursive(struct binaryTree *root, int data) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return NULL;
    }

    if (data < root->data)
        return findRecursive(root->left, data);
    else if (data > root->data)
        return findRecursive(root->right, data);
    return root;
}

void inOrderTraversal(struct binaryTree *root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%i ", root->data);
        inOrderTraversal(root->right);
    }
}