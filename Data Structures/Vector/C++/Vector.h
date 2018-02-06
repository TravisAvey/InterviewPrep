//
// Created by Travis on 2/3/18.
//

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <exception>

template <class T>
class Vector {
private:
    const size_t SIZE = 16;
    size_t mSize;
    T *data;
    size_t mLength;

    void resize();
public:

    Vector();
    explicit Vector(size_t);

    void push_back(T);
    void pop_back();
    T front() const;
    T back() const;
    T at(size_t) const;
    void insert(T, size_t);
    size_t size() const;
    bool empty() const;
    void clear();

    T &operator[](int);
    friend std::ostream &operator<<(std::ostream, const Vector<T>&);
};

/*
    Default constructor
*/
template <class T>
Vector<T>::Vector() {
    data = new T[SIZE];
    mLength = 0;
    mSize = SIZE;
}

/*
    Constructor with size to init with
*/
template <class T>
Vector<T>::Vector(size_t size) {
    if (size > 0) {
        data = new T[size];
        mLength = 0;
        mSize = size;
    } else {
        throw std::out_of_range("Vector's size cannot be 0 or less");
    }
}

/*
    This method adds one item to
    the vector
*/
template <class T>
void Vector<T>::push_back(T item) {
    // if the size is greater than array
    if (mLength >= mSize -1)
        // resize the array
        resize();
    // add item to the array
    data[mLength++] = item;
}

/*
    This method removes the last
    item from the vectir
*/
template <class T>
void Vector<T>::pop_back() {
    // set last item to int min
    // and reduce the length by one
    data[mLength--] = INT64_MIN;
}

/*
    This method returns the front item
    from the vector
*/
template <class T>
T Vector<T>::front() const {
    return data[0];
}

/*
    This method returs the back item
    from the vector
*/
template <class T>
T Vector<T>::back() const {
    return data[mLength-1];
}

/*
    This method returns the item at
    the index supplied by the user
*/
template <class T>
T Vector<T>::at(size_t index) const {
    return data[index];
}

/*
    This method returns true if
    the vector is emtpy, false otherwise
*/
template <class T>
bool Vector<T>::empty() const {
    return mLength == 0;
}

/*
    This method clears the array
    and 'resets'
*/
template <class T>
void Vector<T>::clear() {
    // set all items to int min
    for (size_t i=0; i<mLength; i++)
        data[i] = INT64_MIN;
    // set length and size
    mLength = 0;
    // set array to new array with default size
    // or size user set in constructor
    data = new T[mSize];
}

/*
    This method returns how many elements are
    in the vector
*/
template <class T>
size_t Vector<T>::size() const {
    return mLength;
}

/*
    This is a helper method that doubles
    the array size
*/
template <class T>
void Vector<T>::resize() {
    // create a new array
    auto *newArr = new T[mSize*2];
    // copy old data into new array
    std::copy(data, data + std::min(mSize, mSize*2), newArr);
    // set the data's address to newArr address
    data = newArr;
    // double the size
    mSize *= 2;
}

/*
    Operator overload []
    So user can use vector[index]
*/
template <class T>
T &Vector<T>::operator[](size_t index) {
    if (index >= mSize)
        throw std::out_of_range("Out of range");

    return data[index];
}

/*
    Operator overload <<
    so user can use vector with std::cout <<
*/
template <class T>
std::ostream &operator<<(std::ostream out, const Vector<T> &v) {
    for (int i=0; i<v.size(); i++)
        out << v.data[i] << ' ';
    return out;
}

/*
    This method inserts the item at the index
    supplied
*/
template<class T>
void Vector<T>::insert(T item, size_t index) {
    // if greater than, resize array
    if (mLength++ >= mSize)
        resize();
    
    // shift everything over to the right from index supplied
    for (size_t i=mLength-1; i>=index; i--)
        data[i+1] = data[i];
    // set item to index supplied
    data[index] = item;
}

#endif //__VECTOR_H__
