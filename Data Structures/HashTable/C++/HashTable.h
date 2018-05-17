#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <string>

template <class K, class V>
class Entry {
private:
    K mKey;
    V mValue;
    Entry *next;

public:
    Entry(K, V);
    std::string toString() const;
};

template <class K, class V>
class HashTable {
private:
    const int SIZE = 4;
    Entry<K, V> entries[];
public:
    HashTable();
    void put(K, V);

};

template <class K, class V>
HashTable<K, V>::HashTable() {
    entries = new Entry<K, V>[SIZE];
}

template <class K, class V>
void HashTable<K, V>::put(K key, V value) {
    // get hash
    // TODO: create get hash method
    int hash = 0;
    Entry<K, V> *entry = new Entry<K, V>();

}

template <class K, class V>
Entry<K, V>::Entry(K key, V value) {
    mKey = key;
    mValue = value;
    next = nullptr;
}

template <class K, class V>
std::string Entry<K, V>::toString() const {
    return "[" + mKey + ":" + mValue + "]";
}

#endif