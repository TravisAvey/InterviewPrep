//
// Created by travis on 2/5/18.
//

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <cstddef>
#include <stdexcept>

template <class T>
class Queue {
private:
    const size_t SIZE = 16;
    
    size_t front;   // front of the queue
    size_t back;    // back of the queue
    size_t mSize;   // size of the queue
    size_t N;       // the number of items currently in queue
    T *queue;       // the underlying array of the queue
    
    void setUp(size_t);
public:

    Queue();
    explicit Queue(size_t);
    void enQueue(T);
    T deQueue();
    bool empty() const;
    size_t size() const;
    
};

template<class T>
Queue<T>::Queue() {
    setUp(SIZE);
}

template<class T>
Queue<T>::Queue(size_t size) {
    setUp(size);
}

template<class T>
void Queue<T>::enQueue(T item) {
    if (empty())
        front = back = 0;
    else {
        back = (back+1) % mSize;
    }
    queue[back] = item;
    N++;
}

template<class T>
T Queue<T>::deQueue() {
    if (empty())
        throw std::out_of_range("Queue is empty");
    T item = queue[front];
    if (front == back)
        front = back = (size_t) -1;
    else
        front = (front + 1) % mSize;
    N--;
    return item;
}

template<class T>
bool Queue<T>::empty() const {
    return N == 0;
}

template<class T>
void Queue<T>::setUp(size_t s) {
    mSize = s;
    queue = new T[mSize];
    front = back = (size_t) -1;
    N = 0;
}

template<class T>
size_t Queue<T>::size() const {
    return N;
}

#endif
