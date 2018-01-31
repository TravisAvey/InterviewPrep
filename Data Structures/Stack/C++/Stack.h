#ifndef __STACK_H__
#define __STACK_H__

#define SIZE 16

#include <iostream>
#include <stdexcept>

template <class T>
class Stack {
private:
    T data[SIZE];
    int size;
    int top;
public:
    Stack();
    void push(T);
    T pop();
    T peek() const;
    bool isEmpty() const;

};

template <class T>
Stack<T>::Stack() {
    top = -1;
    size = SIZE;
}

template <class T>
void Stack<T>::push(T item) {
    if (top >= size) {
        // TODO: implement a method to resize array
        std::cout << "Overflow\n";
        throw std::out_of_range("Stack is full");
    }
    data[++top] = item;

}

template <class T>
T Stack<T>::pop() {
    if (top < 0) {
        std::cout << "Underflow\n";
        throw std::out_of_range("Stack is empty");
    }
    return data[top--];
}

template <class T>
T Stack<T>::peek() const {
    if (top < 0) {
        std::cout << "Stack is empty!\n";
        throw std::out_of_range("Stack is empty");
    }
    return data[top];
}

template <class T>
bool Stack<T>::isEmpty() const {
    return (top < 0);
}

#endif