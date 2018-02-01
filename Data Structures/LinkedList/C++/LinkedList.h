#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <stdexcept>

template <class T>
class LinkedList {
private:

    struct Node {
        T data;
        Node *next;
    };

public:
    LinkedList();
    ~LinkedList();
};


template <class T>
LinkedList<T>::LinkedList() {

}


template <class T>
LinkedList<T>::~LinkedList() {
    
}

#endif