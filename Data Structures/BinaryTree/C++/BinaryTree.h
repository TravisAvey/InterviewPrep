//
// Created by travis on 2/7/18.
//

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <cstddef>
#include <iostream>

namespace bt {
    template<class T>
    struct node {
        T data;
        node *left;
        node *right;
    };
}

template <class T>
class BinaryTree {
private:


    size_t N;
    bt::node<T> *root;

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

template <class T>
BinaryTree<T>::BinaryTree() {
    N = 0;
    root = nullptr;
}

template <class T>
bt::node<T> * BinaryTree<T>::insert(bt::node<T> *n, T item) {
    if (n == nullptr) {
        return newNode(item);
    } else {
        if (item < n->data)
            n->left = insert(n->left, item);
        else
            n->right = insert(n->right, item);

    }
    return n;
}

template <class T>
bool BinaryTree<T>::find(T item) const {
    return find(root, item);
}

template <class T>
size_t BinaryTree<T>::size() const {
    return N;
}

template <class T>
size_t BinaryTree<T>::height() const {
    return 0;
}

template <class T>
bt::node<T> *BinaryTree<T>::newNode(T item) {
    auto temp = new bt::node<T>;
    temp->data = item;
    temp->left = temp->right = nullptr;
    return temp;
}

template <class T>
void BinaryTree<T>::preOrderTraversal(bt::node<T> *n) const {
    if (n) {
        std::cout << n->data << ' ';
        preOrderTraversal(n->left);
        preOrderTraversal(n->right);
    }
}

template<class T>
void BinaryTree<T>::insert(T item) {
    root = insert(root, item);
    N++;
}

template<class T>
void BinaryTree<T>::inOrderTraversal() const {
    inOrderTraversal(root);
    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::preOrderTraversal() const {
    preOrderTraversal(root);
    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::postOrderTraversal(bt::node<T> *n) const {
    if (n) {
        postOrderTraversal(n->left);
        postOrderTraversal(n->right);
        std::cout << n->data << ' ';
    }
}

template<class T>
void BinaryTree<T>::postOrderTraversal() const {
    postOrderTraversal(root);
    std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::inOrderTraversal(bt::node<T> *n) const {
    if (n) {
        inOrderTraversal(n->left);
        std::cout << n->data << ' ';
        inOrderTraversal(n->right);
    }
}

template<class T>
bool BinaryTree<T>::find(bt::node<T> *node, T item) const {
    if (node == nullptr) {
        return false;
    }

    while (node != nullptr) {
        if (item == node->data)
            return true;
        else if (item > node->data)
            node = node->right;
        else
            node = node->left;
    }
    return false;
}

template<class T>
T BinaryTree<T>::findMax(bt::node<T> *node) const {
    size_t root, left, right, max = (size_t) INT64_MIN;

    if (node) {
        root = node->data;
        left = findMax(node->left);
        right = findMax(node->right);

        if (left > right)
            max = left;
        else
            max = right;

        if (root > max)
            max = root;
    }
    return max;
}

template<class T>
T BinaryTree<T>::findMax() const {
    return findMax(root);
}

#endif
