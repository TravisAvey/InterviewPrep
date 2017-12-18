#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>

// the structure of each node
// for the linked list
struct Node {
    int data;
    struct Node *next;
};

int length(struct Node *);
void printList(struct Node *);
void pushFront(struct Node **, int);
void pushBack(struct Node **, int);
void insertAt(struct Node **, int, int);
int popFront(struct Node **);
int popBack(struct Node **);
void removeNode(struct Node **, int);
void error(char *);


#endif
