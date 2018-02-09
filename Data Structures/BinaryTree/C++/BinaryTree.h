//
// Created by travis on 2/7/18.
//

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <cstddef>
#include <iostream>

namespace bt {
    // nodes for each leaf in the tree
    template<class T>
    struct node {
        // the data: int, string, class, etc
        T data;
        // left and right pointers
        node *left;
        node *right;
    };
}

template <class T>
class BinaryTree {
private:
    
    size_t N;           // the current number of items in the tree
    bt::node<T> *root;  // the root of the tree

    // Private methods no hide the need to pass the bt::node
    bt::node<T> *newNode(T);
    bt::node<T> * insert(bt::node<T> *, T);
    void preOrderTraversal(bt::node<T> *) const;
    void postOrderTraversal(bt::node<T> *) const;
    void inOrderTraversal(bt::node<T> *) const;
    bool find(bt::node<T> *, T) const;
    T findMax(bt::node<T>*) const;
public:
    
    BinaryTree();
    void insert(T);
    bool find(T) const;
    size_t size() const;
    size_t height() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    void inOrderTraversal() const;
    T findMax() const;
};

/*
    Public constructor
*/
template <class T>
BinaryTree<T>::BinaryTree() {
    // initilize the count and root
    N = 0;
    root = nullptr;
}

/*
    This method inserts the given item into the tree
        -Private method, called from public interface
*/
template <class T>
bt::node<T> * BinaryTree<T>::insert(bt::node<T> *n, T item) {
    // if current node is a null pointer, return the new node
    if (n == nullptr) {
        return newNode(item);
    } else {
        // if the item is less than current node's item
        if (item < n->data)
            // insert to the left
            n->left = insert(n->left, item);
        else
            // else, it's greater insert to the right
            n->right = insert(n->right, item);

    }
    // return the node
    return n;
}

/*
    Public facing method to insert
*/
template<class T>
void BinaryTree<T>::insert(T item) {
    // call private method to insert
    root = insert(root, item);
    // increment the count of items
    N++;
}

/*
    This is the private method to find the given
    item in the tree
    returns true if item is in the tree, false if not
*/
template<class T>
bool BinaryTree<T>::find(bt::node<T> *node, T item) const {
    // if current node is null, return false
    // (if root is null, nothing in tree)
    if (node == nullptr) {
        return false;
    }

    // loop while the current node isn't a null pointer
    while (node != nullptr) {
        // if we found the item return true
        if (item == node->data)
            return true;
        // if item is greater, then move to the right
        else if (item > node->data)
            node = node->right;
        else
            // else it's less, move to the left
            node = node->left;
    }
    // if we fall out of loop without returning
    // true, then the item isn't in the tree
    return false;
}

/*
    This is the public facing method to find the 
    item in the tree
*/
template <class T>
bool BinaryTree<T>::find(T item) const {
    // start at root and find the item
    return find(root, item);
}

/*
    This method returns the number of items
    currently in the tree
*/
template <class T>
size_t BinaryTree<T>::size() const {
    return N;
}

/*
    TODO: implement finding the height of the tree
*/
template <class T>
size_t BinaryTree<T>::height() const {
    return 0;
}

/*
    This is a private helper method to create
    a new node
*/
template <class T>
bt::node<T> *BinaryTree<T>::newNode(T item) {
    // initialize a new node
    auto node = new bt::node<T>;
    // set the data
    node->data = item;
    // left and right init to null pointers
    node->left = temp->right = nullptr;
    // return the new node
    return node;
}

/*
    This is the private method for pre order traversal
*/
template <class T>
void BinaryTree<T>::preOrderTraversal(bt::node<T> *n) const {
    // if the current node isn't null
    if (n) {
        // ouput before traversing to next (pre-order)
        std::cout << n->data << ' ';
        // recurse on the left
        preOrderTraversal(n->left);
        // recurse on the right
        preOrderTraversal(n->right);
    }
}

/*
    This is the public facing method for
    pre order traversal
*/
template<class T>
void BinaryTree<T>::preOrderTraversal() const {
    // call private method starting at root
    preOrderTraversal(root);
    // output new line after preorder is done
    std::cout << std::endl;
}

/*
    This method is the private method for in
    order traversal
*/
template<class T>
void BinaryTree<T>::inOrderTraversal(bt::node<T> *n) const {
    // if n isn't null
    if (n) {
        // move left recursively
        inOrderTraversal(n->left);
        // output current node's data
        std::cout << n->data << ' ';
        // move right recursively
        inOrderTraversal(n->right);
    }
}

/*
    Public facing method for inorder traversal
*/
template<class T>
void BinaryTree<T>::inOrderTraversal() const {
    // call private method starting at root
    inOrderTraversal(root);
    // output new line when traversal is done
    std::cout << std::endl;
}

/*
    Private method for post order traversal
*/
template<class T>
void BinaryTree<T>::postOrderTraversal(bt::node<T> *n) const {
    // if current node is good
    if (n) {
        // recurse to the left
        postOrderTraversal(n->left);
        // recurse to the right
        postOrderTraversal(n->right);
        // output current node's data
        std::cout << n->data << ' ';
    }
}

/*
    Public facing method for post order
    traversal
*/
template<class T>
void BinaryTree<T>::postOrderTraversal() const {
    // post order starting at root
    postOrderTraversal(root);
    // output new line when traversal completes
    std::cout << std::endl;
}

/*
    Private facing method to find the max item
    in the tree
    
    TODO: will this work with std::string?
*/
template<class T>
T BinaryTree<T>::findMax(bt::node<T> *node) const {
    // declare variables to hold each node's data
    size_t root, left, right, max = (size_t) INT64_MIN;

    // if the node isn't null
    if (node) {
        // set the root's data
        root = node->data;
        // recurse on the left
        left = findMax(node->left);
        // recurse on the rith
        right = findMax(node->right);
        
        // if left is greater
        if (left > right)
            // set max as left
            max = left;
        else
            // else right is greater set as max
            max = right;
        
        // check if root's data is greater
        if (root > max)
            max = root;
    }
    // return the max
    return max;
}

/*
    Public facing method to find the maximum
    value in the tree
*/
template<class T>
T BinaryTree<T>::findMax() const {
    // return the max, pass root as arg
    return findMax(root);
}

#endif
