#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <string>
#include <functional>


template <class K, class V>
class HashTable {
private:


    struct Entry {
        K key;
        V value;
        Entry *next;
    };

//    Entry *next;
    const int SIZE = 16;
    Entry *entries;

    int getHash(K);
public:
    HashTable();
    void put(K, V);

};

template <class K, class V>
HashTable<K, V>::HashTable() {
    entries = new Entry[SIZE];

    for (int i=0; i<SIZE; i++)
        // no match for operator= ?
        entries[i] = nullptr;
}

template <class K, class V>
void HashTable<K, V>::put(K key, V value) {
    int hash = getHash(key);
    Entry *entry = new Entry;
    entry->key = key;
    entry->value = value;
    entry->next = nullptr;

    if (entries[hash].next == nullptr) {
        entries[hash] = *entry;
    } else {

        // I think this should be set from entries[hash] .. ?
        Entry temp = entry[hash];

        while (temp.next != nullptr)
            // Entry and Entry * are not compatible... ?
            temp = temp.next;

        temp.next = entry;
    }
}

template <class K, class V>
int HashTable<K, V>::getHash(K key) {
    std::hash<K> hash;
    size_t keyHash = hash(key);
    return static_cast<int>(keyHash % SIZE);
}



#endif