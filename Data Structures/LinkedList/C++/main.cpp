#include "LinkedList.h"
#include <iostream>

void menu(LinkedList<int> *);
void handleChoice(const char &, LinkedList<int> *);

int main(int argc, char **argv) {
    LinkedList<int> *linkedList = new LinkedList<int>();
    menu(linkedList);
    return 0;
}


void menu(LinkedList<int> *list) {

    char choice;

    do {
        std::cout << "Enter a choice\n"
                  << "\t1) Enter at front\n"
                  << "\t2) Enter at rear\n"
                  << "\t3) Remove from front\n"
                  << "\t4) Remove from rear\n"
                  << "\t5) Display value at front\n"
                  << "\t6) Display value at rear\n"
                  << "\t7) Display value at index\n"
                  << "\t8) Display the list\n"
                  << "\t9) Reverse the list\n"
                  << "\ts) Display the size of the list\n"
                  << "Q or q to quit\n\n";
        printf("> ");
        choice = std::getchar();
        std::cin.ignore();
        if (choice == 'q' || choice == 'Q')
            break;
        std::cout << std::endl;
        handleChoice(choice, list);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "================================================\n";
    } while (true);

}

void handleChoice(const char &choice, LinkedList<int> *list) {

    switch (choice) {
        case '1': {
            printf("enter a value> ");
            std::string value;
            std::cin >> value;
            std::cin.ignore();
            list->pushFront(std::stoi(value));
            break;
        }
        case '2': {
            printf("enter a value> ");
            std::string value;
            std::cin >> value;
            std::cin.ignore();
            list->pushBack(std::stoi(value));
            break;
        }
        case '3': {
            if (list->size() > 0) {
              printf("removing front value\n");
              int value = list->popFront();
              printf("Value from front: %i\n", value);
            } else
              printf("The list is empty!\n");
            break;
        }
        case '4': {
            if (list->size() > 0) {
              printf("removing back value\n");
              int value = list->popBack();
              printf("Value from back: %i\n", value);
            } else
              printf("The list is empty\n");
            break;
        }
        case '5': {
            if (list->size() > 0) {
              printf("Display front value\n");
              printf("Value at front: %i\n", list->front());
            } else
              printf("The list is empty\n");
            break;
        }
        case '6': {
            if (list->size() > 0) {
              printf("Display back value\n");
              printf("Value at back: %i\n", list->back());
            } else
              printf("The list is empty\n");
            break;
        }
        case '7': {
            if (list->size() > 0) {
              printf("Enter index> ");
              std::string value;
              std::cin >> value;
              std::cin.ignore();
              int val = list->valueAt(std::stoi(value));
              printf("Value at %i = %i\n", std::stoi(value), val);
            } else
              printf("The list is empty\n");
            break;
        }
        case '8':
            if (list->size() > 0) {
              printf("displaying the list\n");
              list->display();
            } else
              printf("The list is empty\n");
            break;
        case '9':
            printf("reverse the list\n");
            printf("Not yet implemented\n");
            break;
        case 'S':
        case 's': {
            printf("Size of LinkedList: %i\n", list->size());
            break;
        }
        default:
            printf("Unknown selection, please try again\n");
            break;
        
    }
}
