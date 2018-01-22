#include "binary_tree.h"

/*
    This method handles inserting a new node in the binary tree
    Pass a pointer to the root of the tree
*/
struct binaryTree *insert(struct binaryTree *root, int data) {
    // if root is null, we have no other nodes
    if (root == NULL) {
        // allocate memory
        root = (struct binaryTree *) malloc((sizeof (struct binaryTree)));

        // if root is null
        if (root == NULL) {
            // we have an error, return
            fprintf(stderr, "Memory Error constructing the root of the tree\n");
            return NULL;
        } else {
            // set the data and left and right to null
            root->data = data;
            root->left = root->right = NULL;
        }
    } else {
        // if the data is less than the root
        if (data < root->data) {
            // recursive call to insert on the left side
            root->left = insert(root->left, data);
        // if the data is greater than the root
        } else if (data > root->data) {
            // recursive call to insert on the right side
            root->right = insert(root->right, data);
        }
    }
    // return the root
    return root;
}

/*
    This method finds the data in quesiton in the tree
*/
int find(struct binaryTree *root, int data) {
    // if root is empty
    if (root == NULL){
        // output message return false
        printf("Tree is empty\n");
        return 0;
    }

    // while root isn't null
    while (root) {
        // if data is the current data
        if (data == root->data)
            // return true
            return 1;
        // else if the data is greater
        else if (data > root->data)
            // set root to next on the right
            root = root->right;
        // else if the data is less
        else
            // set root to next on the right
            root = root->left;
    }
    // fall out of while loop, return false
    return 0;
}

/*
    This meghot finds the data in question within the tree
    uses recursion to find the data
*/
struct binaryTree *findRecursive(struct binaryTree *root, int data) {
    // base case:
    // if root is null
    if (root == NULL) {
        // output message and return null
        printf("Tree is empty\n");
        return NULL;
    }

    // If data is less than the roots data
    if (data < root->data)
        // recurse to the left
        return findRecursive(root->left, data);
    // if data is greater
    else if (data > root->data)
        // recurse on the right
        return findRecursive(root->right, data);
    // finally return the root
    return root;
}

/*
    This method outputs the tree in pre order traversal
    uses recursion to accomplish
*/
void preOrderTraversal(struct binaryTree *root) {
    if (root) {
        printf("%i ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

/*
    This method outputs the tree in order traversal
    uses recursion
*/
void inOrderTraversal(struct binaryTree *root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%i ", root->data);
        inOrderTraversal(root->right);
    }
}

/*
    This method outputs the tree in post order traversal
    uses recursion
*/
void postOrderTraversal(struct binaryTree *root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%i ", root->data);
    }
}

/*
    This method finds the max within the tree
*/
int findMax(struct binaryTree *root) {
    // TODO: change this to INT_MIN ?
    int rootVal, left, right, max = -99999;

    // if the root is not null
    if (root != NULL) {
        // set the temp variables
        rootVal = root->data;
        // recursively:
        // find max on left
        left = findMax(root->left);
        // find max on right
        right = findMax(root->right);

        // if left is greater than right, set max
        if (left > right)
            max = left;
        // if right is greater, set max
        else 
            max = right;
        // if the root is the greatest, set max
        if (rootVal > max)
            max = rootVal;
    }
    // return the max
    // TODO: if was root was null (?) it will return INT_MIN
    return max;
}

/*
    This method returns the size of the tree
*/
int size(struct binaryTree *root) {
    // if root is null, tree is emtpy
    if (root == NULL)
        return 0;
    else
        // we add one here for current node
        return size(root->left) + 1 + size(root->right);
}

/*
    This method returns the height of the tree
    Uses recursion
*/
int treeHeight(struct binaryTree *root) {
    int left, right;
    // if root is null, 0 size
    if (root == NULL)
        return 0;
    else {
        // recurse on the left side
        left = treeHeight(root->left);
        // recurse on the right side
        right = treeHeight(root->right);
        // if left is greater return left
        if (left > right)
            return left + 1;
        // right is greater, return
        else
            return right + 1;
        // +1 to the above because the root
    }
}