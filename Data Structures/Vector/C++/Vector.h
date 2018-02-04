//
// Created by Travis on 2/3/18.
//

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <exception>

template <class T>
class Vector {
private:
    const int SIZE = 16;
    int mSize;
    T *data;
    u_int64_t mLength;

    void resize();
public:

    Vector();
    Vector(int);
    void add(T);
    u_int64_t length() const;
    T &operator[](int);

    friend std::ostream &operator<<(std::ostream, const Vector<T>&);
};

template <class T>
Vector<T>::Vector() {
    data = new T[SIZE];
    mLength = 0;
    mSize = SIZE;
}

template <class T>
Vector<T>::Vector(int size) {
    if (size > 0) {
        data = new T[size];
        mLength = 0;
        mSize = size;
    } else {
        throw std::out_of_range("Vector's size cannot be 0 or less");
    }
}

template <class T>
void Vector<T>::add(T item) {
    if (mLength >= mSize -1)
        resize();

    data[mLength++] = item;
}

template <class T>
u_int64_t Vector<T>::length() const {
    return mLength;
}

template <class T>
void Vector<T>::resize() {
    auto *newArr = new T[mSize*2];
    std::copy(data, data + std::min(mSize, mSize*2), newArr);
    data = newArr;
    mSize *= 2;
}

template <class T>
T &Vector<T>::operator[](int index) {
    if (index >= mSize)
        throw std::out_of_range("Out of range");

    return data[index];
}

template <class T>
std::ostream &operator<<(std::ostream out, const Vector<T> &v) {
    for (int i=0; i<v.length(); i++)
        out << v.data[i] << ' ';
    return out;
}
#endif //__VECTOR_H__
