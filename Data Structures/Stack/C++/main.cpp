#include <iostream>
#include "Stack.h"

int main(int argc, char **argv) {

    Stack<int> stack;
    stack.push(7);
    stack.push(8);
    stack.push(23);
    stack.push(13);
    stack.push(3);
    stack.push(44);
    stack.push(144);
    stack.push(30);
    stack.push(23);

    if (stack.isEmpty())
        std::cout << "Stack is empty!" << std::endl;
    else
        std::cout << "Stack is not empty!" << std::endl;

    std::cout << "pop(): " << stack.pop() << std::endl;
    std::cout << "top(): " << stack.peek() << std::endl;
    std::cout << "pop(): " << stack.pop() << std::endl;
    std::cout << "pop(): " << stack.pop() << std::endl;
    std::cout << "pop(): " << stack.pop() << std::endl;
    std::cout << "pop(): " << stack.pop() << std::endl;
    std::cout << "pop(): " << stack.pop() << std::endl;
    std::cout << "pop(): " << stack.pop() << std::endl;

    return 0;
}