#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <string>


template <class K, class V>
class HashTable {
private:

    struct Entry<K, V> {
        K key;
        V value;
        Entry *next;
    };

    Entry *next;
    const int SIZE = 16;
    Entry entries[];

    int getHash(K);
public:
    HashTable();
    void put(K, V);

};

template <class K, class V>
HashTable<K, V>::HashTable() {
    entries = new Entry[SIZE];

    for (int i=0; i<SIZE; i++)
        entries[i] = nullptr;
}

template <class K, class V>
void HashTable<K, V>::put(K key, V value) {
    int hash = getHash(key);
    auto *entry = new Entry;
    entry->key = key;
    entry->value = value;
    entry->next = nullptr;

    if (entries[hash].next == nullptr) {
        entries[hash] = *entry;
    } else {

        Entry temp<V> = entry[hash];

        while (temp.next != nullptr)
            temp = temp.next;

        temp.next = entry;
    }
}

template <class K, class V>
int HashTable<K, V>::getHash(K key) {
    auto hash = std::hash<K>(key);

    //int hash = std::hash<K>{key};
    return  ((int)hash) % SIZE;
}



#endif