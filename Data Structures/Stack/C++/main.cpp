#include <iostream>
#include "Stack.h"

int main(int argc, char **argv) {

    Stack<int> stack;
    stack.push(7);
    stack.push(8);
    stack.push(23);

    std::cout << "isEmpty(): " << stack.isEmpty() << std::endl;
    std::cout << "pop(): " << stack.pop() << std::endl;
    std::cout << "top(): " << stack.peek() << std::endl;

    return 0;
}