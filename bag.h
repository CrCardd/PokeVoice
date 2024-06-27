#include "mons.h"
#ifndef bag_h
#define bag_h

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

typedef struct Bag
{
    NodeList *head;
    NodeList *tail;
    int size;
}Bag;

void addBag(Bag *list, Item *value)
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

void initBag(Bag * list)
{
    Item *potion = malloc(sizeof(Item));
    strcpy(potion->name, "Potion");
    potion->qtd = 5;
    potion->type = 1;

    Item *elixir = malloc(sizeof(Item));
    strcpy(elixir->name, "Elixir");
    elixir->qtd = 5;
    elixir->type = 2;

    Item *revive = malloc(sizeof(Item));
    strcpy(revive->name, "Revive");
    revive->qtd = 3;
    revive->type = 3;

    Item *rope = malloc(sizeof(Item));
    strcpy(rope->name, "Rope");
    rope->qtd = 2;
    rope->type = 4;

    addBag(list, potion);
    addBag(list, elixir);
    addBag(list, revive);
    addBag(list, rope);
}

Bag * BagConstructor()
{
    Bag * new_linked = malloc(sizeof(Bag));

    new_linked->head = NULL;
    new_linked->size = 0;

    initBag(new_linked);

    return new_linked;
}

Item removeBag(Bag * list, int index)
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

Item getBag(Bag * list, int index)
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

Item useItem(Bag * list, int index)
{
    if(index >= list->size)
        return;
    
    NodeList * iterator = list->head;

    for (int i = 0; i < index; i++)
    {
        iterator = iterator->next;
    }

    iterator->value.qtd --;

    return iterator->value;
}

void getItem(Bag * list, int index)
{
    if(index >= list->size)
        return;
    
    NodeList * iterator = list->head;

    for (int i = 0; i < index; i++)
    {
        iterator = iterator->next;
    }

    iterator->value.qtd ++;

}

#endif // !LinkedList