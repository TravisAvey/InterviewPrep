#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <string>
#include <functional>

/*
    The node class to hold each
    key/value pair of the hash table
*/
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

/*
    The hash table class.
    Made up of nodes for each key value pair
*/
template <class K, class V>
class HashTable {
private:
    // Needed pointer/pointer here because
    // issues when assigning in constructor
    Node<K, V> **entries;
    const int SIZE = 16;
public:

    // constructor
    HashTable() {
        // set the entries to new node of SIZE
        entries = new Node<K, V>*[SIZE];
        // assign each to nullptr
        for (int i=0; i<SIZE; i++)
            entries[i] = nullptr;
    }

    /*
        This method returns the value
        when the key is passed
    */
    V get(K key) {
        // get the hash -> simple modulus operation
        int hash = (key % SIZE);

        // loop until we find the key, or we get to a null pointer
        while (entries[hash] != nullptr && entries[hash]->getKey() != key) {
            hash = (hash + 1) % SIZE;
        }

        // if current is a null pointer, return null
        if (entries[hash] == nullptr)
            return nullptr;
        else
            // else we found the value, return it
            return entries[hash]->getValue();
    }

    /*
        This method adds a new key/value pair to the
        hashtable
    */
    void put(K key, V value) {
        // create a hash
        int hash = (key % SIZE);
        // loop while not null / key isn't key
        while (entries[hash] != nullptr && entries[hash]->getKey() != key)
            hash = (hash + 1) % SIZE;
        // if hash collision, delete current
        if (entries[hash] != nullptr)
            delete entries[hash];
        // set current hash to new node with key/value pair
        entries[hash] = new Node<K, V>(key, value);
    }
};


#endif