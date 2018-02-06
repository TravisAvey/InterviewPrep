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
    const size_t SIZE = 16; // default queue size
    
    size_t front;           // front of the queue
    size_t back;            // back of the queue
    size_t mSize;           // size of the queue
    size_t N;               // the number of items currently in queue
    T *queue;               // the underlying array of the queue
    
    void setUp(size_t);
public:

    Queue();
    explicit Queue(size_t);
    void enQueue(T);
    T deQueue();
    bool empty() const;
    size_t size() const;
    
};

/*
    Default constructor
        calls setup with default size
*/
template<class T>
Queue<T>::Queue() {
    setUp(SIZE);
}

/*
    Constructor
        calls setup with passed param size
*/
template<class T>
Queue<T>::Queue(size_t size) {
    setUp(size);
}

/*
    This method enQueues an item
    in the queue
*/
template<class T>
void Queue<T>::enQueue(T item) {
    // if empty, set front and back to 0 (array pos)
    if (empty())
        front = back = 0;
    else {
        // set back to next location
        // if back was 2 and size is 16:
        // loc of back will be (2+1)%16 = 3
        back = (back + 1) % mSize;
    }
    // enqueue the item
    queue[back] = item;
    // increment the size of the queue
    N++;
}

/*
    This method deQueue's an item from the queue
*/
template<class T>
T Queue<T>::deQueue() {
    // if empty, throw error
    if (empty())
        throw std::out_of_range("Queue is empty");
    // cache the item we are removing
    T item = queue[front];
    // if front is same as back, empty queue now
    if (front == back)
        front = back = (size_t) -1;
    else
        // move the front loc to next loc in queue
        front = (front + 1) % mSize;
    // decrement count
    N--;
    // return the item 
    return item;
}

/*
    This method returns true if the queue is empty
*/
template<class T>
bool Queue<T>::empty() const {
    return (front == -1) && (back == -1);
}

/*
    This method is a helper method to setup the queue
*/
template<class T>
void Queue<T>::setUp(size_t s) {
    // set size
    mSize = s;
    // init the queue with size
    queue = new T[mSize];
    // set front and back to -1 (empty)
    front = back = (size_t) -1;
    // set count to 0
    N = 0;
}

/*
    This method returns the number
    of items in the queue
*/
template<class T>
size_t Queue<T>::size() const {
    return N;
}

#endif
