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
                  << "1) Enter at front\n"
                  << "2) Enter at rear\n"
                  << "3) Remove from front\n"
                  << "4) Remove from rear\n"
                  << "5) Display value at front\n"
                  << "6) Display value at rear\n"
                  << "7) Display value at index\n"
                  << "8) Display the list\n"
                  << "9) Reverse the list\n"
                  << "Q or q to quit\n";
        choice = std::getchar();
        std::cin.ignore();
        if (choice == 'q' || choice == 'Q')
            break;

        handleChoice(choice, list);

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
            printf("removing front value\n");
            int value = list->popFront();
            printf("Value at front: %i\n", value);
            break;
        }
        case '4': {
            printf("rremoving rear value\n");
            int value = list->popBack();
            printf("Value at back: %i\n", value);
            break;
        }
        case '5': {
            printf("display front value\n");
            printf("Value at front: %i\n", list->front());
            break;
        }
        case '6': {
            printf("diplay rear value\n");
            printf("Value at back: %i\n", list->back());
            break;
        }
        case '7':
            printf("displaying value at index..\n");
            break;
        case '8':
            printf("displaying the list\n");
            list->display();
            break;
        case '9':
            printf("reverse the list\n");
            printf("Not yet implemented\n");
            break;
        default:
            printf("Unknown selection, please try again\n");
            break;
        
    }
}