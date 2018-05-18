#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <string>

template <class K, class V>
class Entry {
private:
    K mKey;
    V mValue;

public:

    Entry *next;
    Entry(K, V);
    std::string toString() const;
};

template <class K, class V>
class HashTable {
private:
    const int SIZE = 16;
    Entry<K, V> entries[];

    int getHash(K);
public:
    HashTable();
    void put(K, V);

};

template <class K, class V>
HashTable<K, V>::HashTable() {
    entries = new Entry<K, V>[SIZE];

    for (int i=0; i<SIZE; i++)
        entries[i] = nullptr;
}

template <class K, class V>
void HashTable<K, V>::put(K key, V value) {
    int hash = getHash(key);
    Entry<K, V> *entry = new Entry<K, V>(key, value);
    if (!entries[hash]) {
        entries[hash] = entry;
    } else {
        Entry<K, V> temp = entries[hash];

        while (temp.next != null)
            temp = temp.next;
        
        temp.next = entry;
    }
}

template <class K, class V>
int HashTable<K, V>::getHash(K key) {
    size_t hash = std::hash<K>{key};
    return (int) hash % SIZE;
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