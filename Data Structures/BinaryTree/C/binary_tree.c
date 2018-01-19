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

int find(struct binaryTree *root, int data) {
    if (root == NULL){
        printf("Tree is empty\n");
        return 0;
    }

    while (root) {
        if (data == root->data)
            return 1;
        else if (data > root->data)
            root = root->right;
        else
            root = root->left;
    }

    return 0;
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

void preOrderTraversal(struct binaryTree *root) {
    if (root) {
        printf("%i ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(struct binaryTree *root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%i ", root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct binaryTree *root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%i ", root->data);
    }
}

int findMax(struct binaryTree *root) {
    int rootVal, left, right, max = -99999;

    if (root != NULL) {

        rootVal = root->data;
        left = findMax(root->left);
        right = findMax(root->right);

        if (left > right)
            max = left;
        else 
            max = right;
        if (rootVal > max)
            max = rootVal;
    }

    return max;
}

int size(struct binaryTree *root) {
    if (root == NULL)
        return 0;
    else
        // we add one here for current node
        return size(root->left) + 1 + size(root->right);
}

int treeHeight(struct binaryTree *root) {
    int left, right;
    if (root == NULL)
        return 0;
    else {
        left = treeHeight(root->left);
        right = treeHeight(root->right);
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}