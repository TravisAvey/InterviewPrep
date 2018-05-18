#include "HashTable.h"
#include <iostream>

int main(int argc, char *argv[]) {

    HashTable<int, std::string> hash;

    hash.put(0, "bob");
    hash.put(1, "Jerome");

    return 0;
}