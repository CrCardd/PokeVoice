#ifndef bag_h
#define bag_h
#include "mons.h"

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

Bag * bagConstructor()
{
    Bag * new_bag = malloc(sizeof(Bag));

    new_bag->head = NULL;
    new_bag->size = 0;

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

    addBag(new_bag, potion);
    addBag(new_bag, elixir);
    addBag(new_bag, revive);
    addBag(new_bag, rope);

    return new_bag;
}

Item removeBag(Bag * list, int index)
{
    if(index > list->size)
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









//////////////////////////////////// CRISTIAN
Item getBag(Bag * list, int index)
{
    if(index > list->size)
        return;
    
    NodeList * iterator = list->head;

    for (int i = 1; i < index; i++)
    {
        iterator = iterator->next;
    }

    return iterator->value;
}
//////////////////////////////////// CRISTIAN








Item useItem(Bag * list, int index)
{
    if(index > list->size)
        return;
    
    NodeList * iterator = list->head;

    for (int i = 1; i < index; i++)
    {
        iterator = iterator->next;
    }

    iterator->value.qtd --;

    return iterator->value;
}

void getItem(Bag * list, int index)
{
    if(index > list->size)
        return;
    
    NodeList * iterator = list->head;

    for (int i = 1; i < index; i++)
    {
        iterator = iterator->next;
    }

    iterator->value.qtd ++;

}


void showBag(Bag * list)
{
    NodeList * iterator = list->head;
    int index = 1;

    while (iterator->next != NULL)
    {
        printf("%d - %s\n",index, iterator->value.name);
        iterator = iterator->next;
        index++;
    }
}

#endif // !bag