#ifndef __STACK_H__
#define __STACK_H__

#define SIZE 16

#include <iostream>
#include <stdexcept>

template <class T>
class Stack {
private:

    T *data{nullptr};   // The array of items in the stack
    int size;           // the size of the stack
    int top;            // where the top location is

    void resize();

public:
    Stack();
    ~Stack();
    void push(T);
    T pop();
    T peek() const;
    bool isEmpty() const;

};

/*
    The constructor
        Initialize the object
*/
template <class T>
Stack<T>::Stack() {
    data = new T[SIZE];
    top = -1;
    size = SIZE;
}

/*
    Destructor
        Remove any dynamically allocated memory
*/
template <class T>
Stack<T>::~Stack() {
    delete [] data;
}

/*
    This method pushes an item
    onto the stack
*/
template <class T>
void Stack<T>::push(T item) {
    // if top is out of range
    if (top >= size) {
        // call helper method to resize array
        resize();
    }
    // add item to stack
    data[++top] = item;
}

/*
    This method removes an item
    from the top of the stack
*/
template <class T>
T Stack<T>::pop() {
    // if top is less than 0
    if (top < 0) {
        // we have an empty stack..
        std::cout << "Underflow\n";
        throw std::out_of_range("Stack is empty");
    }
    // remove and return the top of the stack
    return data[top--];
}

/*
    This method returns the top of the
    stack, but keeps the item in the stack
*/
template <class T>
T Stack<T>::peek() const {
    // if we have an empty stack
    if (top < 0) {
        std::cout << "Stack is empty!\n";
        throw std::out_of_range("Stack is empty");
    }

    // return the item on top
    return data[top];
}

/*
    This method returns true
    if the stack is empty
*/
template <class T>
bool Stack<T>::isEmpty() const {
    return (top < 0);
}

// TODO: implement a method to double size of array
template <class T>
void Stack<T>::resize() {

}

#endif