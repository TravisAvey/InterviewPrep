#include "LinkedList.h"
#include <iostream>


int main(int argc, char **argv) {
    LinkedList<int> list;
    if (list.empty())
      printf("Is empty!\n");

    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(7); 

    std::cout << "valueAt(0) " << list.valueAt(0) << std::endl;
    std::cout << "valueAt(1) " << list.valueAt(1) << std::endl;

    list.display();
    std::cout << "popFront " << list.popFront() << std::endl;
    list.display();
    if (!list.empty())
      printf("is not empty!\n");
    list.pushBack(0);
    printf("Size of Linked List %i\n", list.size());
    list.display();
    std::cout << "popBack " << list.popBack() << std::endl;
    list.display(); 
    return 0;
}
