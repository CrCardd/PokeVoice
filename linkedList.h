#include "mons.h"
#ifndef linkedList_H
#define linkedList_H

typedef struct NodeList NodeList;

typedef struct  Item
{
    char name[10];
    int qtd;
    int type;
} Item;

typedef struct NodeList
{
    Item value;
    NodeList *next;
}NodeList;

typedef struct LinkedList
{
    NodeList *head;
    NodeList *tail;
    int size;
}LinkedList;


LinkedList * LinkedListConstructor()
{
    LinkedList * new_linked = malloc(sizeof(LinkedList));

    new_linked->head = NULL;
    new_linked->size = 0;

    return new_linked;
}

void addlist(LinkedList *list, Item *value)
{
    list->size++;
    NodeList *node = malloc(sizeof(NodeList));
    node->value = *value;
    node->next = NULL;

    if(!list->head)
    {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = list->tail->next;

    return;
}

Item removeList(LinkedList * list, int index)
{
    if(index >= list->size)
        return;
    
    list->size--;

    NodeList * aux;

    if(index == 0)
    {
        aux = list->head;

        if(list->size == 1)
            list->head = NULL;
        else
            list->head = list->head->next;
        return aux->value;
    }

    NodeList * iterator = list->head;

    for (int i = 1; i < index; i++)
    {
        iterator = iterator->next;
    }

    aux = iterator->next;

    iterator->next = aux->next;

    return aux->value;
}

Item getList(LinkedList* list, int index)
{
    if(index >= list->size)
        return;
    
    NodeList * iterator = list->head;

    for (int i = 0; i < index; i++)
    {
        iterator = iterator->next;
    }

    return iterator->value;
}

#endif // !LinkedList