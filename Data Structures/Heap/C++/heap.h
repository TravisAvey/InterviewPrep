//
// Created by travis on 4/4/18.
//

#ifndef __HEAP__H
#define __HEAP__H

#include <vector>
#include <iostream>

// namespace for heap type
namespace TYPE {
    // max heap or min heap
    enum type {MAX, MIN};
}

/*
 * This is the Heap ADT
 * Stores the items in a binary tree
 * Depending on TYPE, Max or Min at root
 */
template <class T>
class Heap {

private:
    std::vector<T> *heap;   // underlying structure
    int count;              // current number of items in heap
    TYPE::type mType;       // the type, MAX or MIN

    int parent(int index) const;
    int leftChild(int index) const;
    int rightChild(int index) const;
    void heapify();
    void swap(int i, int j) ;


public:

    Heap();
    explicit Heap(TYPE::type type);
    bool isEmpty() const ;
    int length() const;
    void insert(T val);
    T getMax() const;
    T getMin() const;
    void print();

};

/*
     * Public constructor
     */
    template<class T>
    Heap::Heap() {
        heap = new std::vector<T>;
        count = 0;
        mType = TYPE::MAX;

    }

    /*
     * Constructor with TYPE
     */
    template<class T>
    explicit Heap::Heap(TYPE::type type) {
        heap = new std::vector<T>;
        mType = type;
        count = 0;
    }

    /*
     * This method returns true if the heap is empty
     */
    template<class T>
    bool Heap::isEmpty() const { return count == 0; }

    /*
     * This method returns the length of the heap
     */
    template<class T>
    int Heap::length() const { return count; }

    /*
     * This method inserts a new value into the heap
     */
    template<class T>
    void Heap::insert(T val) {
        // add to heap vector
        heap->push_back(val);
        // call method to satisfy heap property
        heapify();
        // increment count
        count++;
    }

    /*
     * This method gets the max value from heap
     */
    template<class T>
    T Heap::getMax() const {
        // if empty, throw error
        if (isEmpty())
            throw std::out_of_range("Heap is empty");

        // if we are a max type, max will be at root
        if (mType == TYPE::MAX)
            return heap->at(0);

        // get the value at root
        T val = heap->at(0);
        // loop over rest of heap
        for (int i=1; i<heap->size(); i++)
            // if val is less than current
            if (val < heap->at(i))
                // set val current
                val = heap->at(i);
        // fall off loop, return max
        return val;
    }

    /*
     * This method returns the min of the heap
     */
    template<class T>
    T Heap::getMin() const {
        // if empty throw error
        if (isEmpty())
            throw std::out_of_range("Heap is empty");

        // if min type, min at root
        if (mType == TYPE::MIN)
            return heap->at(0);

        // get value at root
        T val = heap->at(0);
        // loop over rest of heap
        for (int i=1; i<heap->size(); i++)
            // if val is greater than current
            if (val > heap->at(i))
                // set val to current
                val = heap->at(i);
        // fall off loop, we have min
        return val;
    }

    /*
     * This method prints out the heap
     */
    template<class T>
    void Heap::print() const {
        for (auto val : *heap)
            std::cout << val << ' ';
        std::cout << std::endl;
    }

    /*
    * This method returns the parent index
    */
    template<class T>
    int Heap::parent(int index) const {
        return (index -1) / 2;
    }

    /*
     * This method returns the left child index
     */
    template<class T>
    int Heap::leftChild(int index) const {
        int left = 2 * index + 1;
        if (left >= count)
            return -1;
        return left;
    }

    /*
     * This method returns the right child index
     */
    template<class T>
    int Heap::rightChild(int index) const {
        int right = 2 * index + 2;
        if (right >= count)
            return -1;
        return right;
    }

    /*
     * This method maintains the heap property based
     * on MAX or MIN type
     */
    template<class T>
    void Heap::heapify() {
        // get the count, starting at bottom of tree
        int index = count;

        // if min type
        if (mType == TYPE::MIN) {
            // while the parent is greater than current index value
            while (heap->at(parent(index)) > heap->at(index)) {
                // swap the values
                swap(index, parent(index));
                // set index to parent
                index = parent(index);
            }
        // max type
        } else {
            // while index is greater than 0 and parent is less than current
            while (index > 0 && heap->at(parent(index)) < heap->at(index)) {
                // swap the 2 values, parent and current
                swap(index, parent(index));
                // move to parent index
                index = parent(index);
            }
        }
    }

    /*
     * Helper method to swap 2 values of the
     * heap, given the 2 indices location
     */
    template<class T>
    void Heap::swap(int i, int j) {
        std::swap(heap->at(i), heap->at(j));
    }


#endif
