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

    bt::node<T> *newNode(T);
public:
    BinaryTree();
    bt::node<T> * insert(bt::node<T> *, T);
    bool find(T) const;
    size_t size() const;
    size_t height() const;
    void preOrderTraversal(bt::node<T> *);
};

template <class T>
BinaryTree<T>::BinaryTree() {
    N = 0;

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
bool BinaryTree<T>::find(T) const {
    return false;
}

template <class T>
size_t BinaryTree<T>::size() const {
    return 0;
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
void BinaryTree<T>::preOrderTraversal(bt::node<T> *n) {
    if (n) {
        std::cout << n->data << ' ';
        preOrderTraversal(n->left);
        preOrderTraversal(n->right);
    }
}

#endif
