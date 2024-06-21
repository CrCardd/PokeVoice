#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define TYPE int

#include <stdlib.h>

typedef struct Node Node;

struct Node{
    Node * next;
    Node * prev;
    TYPE value;
};

typedef struct
{
    Node * head;
    Node * tail;
    int size;
} LinkedList;

LinkedList* linkedlist_constructor()
{
    LinkedList* linkedlist = (LinkedList*) malloc(sizeof(LinkedList));
    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    linkedlist->size = 0;

    return linkedlist;
}

Node* node_constructor(TYPE value)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;

    return node;
}



void addValue(LinkedList* linkedlist, TYPE value)
{
    Node* node = node_constructor(value);

    if(!linkedlist->head)
    {
        linkedlist->head = node;
        linkedlist->head = node;
        linkedlist->size++;
        return;
    }

    linkedlist->tail->next = node;
    node->prev = linkedlist->tail;
    linkedlist->tail = node;
}




void setValue(LinkedList* linkedlist, int index, TYPE value)
{
    if(index >= linkedlist->size || linkedlist->size < 0)
        return;

    Node* current = linkedlist->head;
    while(index--)
        current = getNext(current);
    
    current->value = value;
}






TYPE getValue(LinkedList* linkedlist, int index)
{
    if(index >= linkedlist->size || linkedlist->size < 0)
        return;
        
    Node* current = linkedlist->head;
    while(index--)
        current = getNext(current);
    
    return current->value;
}

Node* getNext(Node* node)
{
    return node->next;
}


#endif