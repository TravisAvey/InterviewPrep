#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <string>
#include <functional>

template <class K, class V>
class Node {
private:
    K key;
    V value;
public:
    Node(K key, V value) {
        this->key = key;
        this->value = value;
    }

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }
};

template <class K, class V>
class HashTable {
private:
    Node<K, V> **entries;
    const int SIZE = 16;
public:

    HashTable() {
        entries = new Node<K, V>*[SIZE];
        for (int i=0; i<SIZE; i++)
            entries[i] = nullptr;
    }

    V get(K key) {
        int hash = (key % SIZE);

        while (entries[hash] != nullptr && entries[hash]->getKey() != key) {
            hash = (hash + 1) % SIZE;
        }

        if (entries[hash] == nullptr)
            return nullptr;
        else
            return entries[hash]->getValue();
    }

    void put(K key, V value) {
        int hash = (key % SIZE);

        while (entries[hash] != nullptr && entries[hash]->getKey() != key)
            hash = (hash + 1) % SIZE;
        if (entries[hash] != nullptr)
            delete entries[hash];
        entries[hash] = new Node<K, V>(key, value);
    }
};


#endif