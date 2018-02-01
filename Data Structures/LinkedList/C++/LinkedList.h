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
    Node *head;
    int N;
public:
    LinkedList();
    ~LinkedList();
    int size() const;
    bool empty() const;
    T valueAt(int) const;
    void pushFront(T);
    T popFront();
    void pushBack(T);
    T popBack();
    T front();
    T back();
    void insert(T, int);
    void reverse();
    void display() const;    
};


template <class T>
LinkedList<T>::LinkedList() {
  N = 0;
  head = nullptr;
}


template <class T>
LinkedList<T>::~LinkedList() {
    
}

/*
    This method removes the first
    item from the list and returns it
*/
template <class T>
T LinkedList<T>::popFront() {
    // store the item
    T item = head->data;
    // set head to head's next
    // effectively removing first node
    head = head->next;
    // return the item
    return item;
}

/*  
    This method pushes the item
    to the front of the Linked List
*/
template <class T>
void LinkedList<T>::pushFront(T item) {
    // create a new node
    Node *node = new Node;
    // set the data to the param
    node->data = item;
    // point new node's next to
    // what head is pointing at
    node->next = head;
    // point head to this new node
    head = node;
    // increment the count of items in list
    N++;
}

/*
    This method returns the value found
    at the index
*/
template <class T>
T LinkedList<T>::valueAt(int index) const {
    // create a pointer for traversal
    Node *current = head;
    // init a counter
    int i = 0;
    // while pointer is not null
    while (current) {
      // if counter is param, break
      if (i == index)
        break;
    // increment counter
    i++;
    // move pointer to next node
    current = current->next;
    }
    // after we break, return the data at the index
    return current->data;
}

/*
    This method returns true if
    the Linked List is empty
*/
template <class T>
bool LinkedList<T>::empty() const {
  // if head is nullptr, list is empty
  return head == nullptr;
}

/*
    This method returns the number of
    items in the Linked List
*/
template <class T>
int LinkedList<T>::size() const {
  return N;
}

/*
    This method displays all the items
    in the linked list
*/
template <class T>
void LinkedList<T>::display() const {
  // create a pointer for traversal
  Node *current = head;
  // while the current is not null
  while (current) {
    // output current data
    std::cout << current->data << ' ';
    // move to next node
    current = current->next;
  }
  // after going through list, print new line
  std::cout << std::endl;
}

#endif
