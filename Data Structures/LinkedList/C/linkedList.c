#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int length(struct Node *);
void printList(struct Node *);
void pushFront(struct Node **, int);


int main(int argc, char **argv) {

    struct Node **linkedList;
    linkedList = (struct Node**) malloc(sizeof(struct Node**));
    pushFront(linkedList, 1);
    pushFront(linkedList, 0);
    pushFront(linkedList, 2);
    printf("Length: %i\n", length((*linkedList)));
    printList((*linkedList));
    return EXIT_SUCCESS;
}

// This method returns the length of the list
// by traversing the list
int length(struct Node *head) {
    // create a current node to traverse
    struct Node *current = head;
    // declare a counter
    int count;
    count = 0;
    // loop through list as long as current
    // is not NULL (which would be the end)
    while (current != NULL) {
        // increment the counter
        count++;
        // set current to the next
        current = current->next;
    }
    // return the count
    return count;
}

// This method loops through the list
// and prints out each datum at each node
void printList(struct Node *head) {
    // get the first node
    struct Node *current = head;
    // init a counter
    int node = 0;
    // while the current is not null
    while (current != NULL) {
        printf("Node %i : %i\n", node, current->data);
        current = current->next;
        node++;
    }
}

void pushFront(struct Node **head, int data) {
    // init a new node
    struct Node *newNode, *p;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    p = *head;
    if (!newNode) {
        fprintf(stderr, "Memory error initializing a new node");
        return;
    }
    newNode->next = p;
    *head = newNode;
}