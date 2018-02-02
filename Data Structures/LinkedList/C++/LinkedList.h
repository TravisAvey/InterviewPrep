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
    T front() const;
    T back() const;
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
  delete head;    
}

/*
  This method removes the last
  item from the list and returns it
*/
template <class T>
T LinkedList<T>::popBack() {
  // if head is empty, throw error
  if (head == nullptr)
    throw std::out_of_range("List is empty!");

  // create nodes for traversal
  Node *prev = nullptr;
  Node *current = head;
  // init item
  T item;
  // loop while the next node isn't the end
  while (current->next) {
    // move prev to current
    prev = current;
    // move current to the next
    current = current->next;
    // store the item
    item = current->data;
  }
  // if prev is not a null pointer
  if (prev != nullptr) {
    // point the prev->next to null
    prev->next = nullptr;
  // else, we didn't go through while loop
  } else {
    // get the data from last item in list
    item = current->data;
    // set the head to nullptr (now empty list)
    head = nullptr;
  }
  // decrement the counter
  N--;
  // return the item
  return item;
}

/*
  This method pushes the new item
  to the back of the list
*/
template <class T>
void LinkedList<T>::pushBack(T item) {
  Node *node = new Node;
  node->data = item;
  if (head == nullptr) {
    pushFront(item);
  } else {
    // point a traversal pointer at head
    Node *current = head;
    Node *prev;
    // while the next isn't null
    while (current != nullptr) {
      prev = current;
      // move to next
      current = current->next;
    }
    // set the next node
    prev->next = node;
    node->next = current;
    N++;
  }
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
    N--;
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
  This method returns the item in the
  front of the list
*/
template <class T>
T LinkedList<T>::front() const {
    // if head is null pointer, empty list
    if (head == nullptr)
        throw std::out_of_range("The list is empty!");
    // return the data from first node
    return head->data;
}

/*
  This method returns the item in
  the back of the list
*/
template <class T>
T LinkedList<T>::back() const {
    // if head is nullptr, empyt list
    if (head == nullptr)
      throw std::out_of_range("The list is empty!");
    // create a node for traversal
    Node *current = head;
    // as long as the next node is good
    while (current->next != nullptr) {
        // move to next node
        current = current->next;
    }
    // return the data from the last node
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
  This method reverses the linked list
*/
template <class T>
void LinkedList<T>::reverse() {
  // only if head isn't pointing
  // to a null pointer 
  if (head != nullptr) {
    // nodes for traversal
    Node *prev, *current, *next;
    // set prev to a null pointer
    prev = nullptr;
    // set current to head
    current = head;
    // as long as current isn't a nullptr
    while (current) {
      // set next to current's next
      next = current->next;
      // set current's next to prev (first will be nullptr)
      current->next = prev;
      // set prev to current
      prev = current;
      // and set current to next
      current = next;
    }
    // finally set head to prev
    head = prev;
  }

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
