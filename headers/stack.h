#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>


typedef struct Room Room;

typedef struct Node Node;

typedef void (*Func)(Room *, int);


// estrutura para para matriz de seleção que será usado para caixas de seleção
typedef struct 
{
    int optY;
    int optX;
    int optY_;
    int optX_;
    void * entity;
} Options;

// mapa que será usado para exibição e gerenciamento de valores
typedef struct
{
    int value;
    void * entity;

} Map;

// struct para gerenciar os dados de 'Options'
typedef struct
{
    int rows;
    int collums;
    Options ** options;
    char * selectName;
} SelectOptions;

// struct para gerenciar os dados de 'Map'
typedef struct MapData
{
    Map** map;
    int rows;
    int collums;
    int screenUpdated;
    SelectOptions selectOptions;
    Func func;


} MapData;

// nó para lista encadeada de eventos
typedef struct Node
{
    MapData * mapData;
    Node *next;
    Node *prev;
}Node;

// Pilha que será utilizada para os eventos do jogo, cada vez que um novo evento ocorrer será colocado no topo da pilha e ganhará prioridade
typedef struct 
{
    Node *head;
    Node *tail;
    int size;
}Stack;


// construtor de um nó
Node* constructor_node(MapData * value)
{
    Node* new_ = (Node*) malloc(sizeof(Node));
    new_->next = NULL;
    new_->prev = NULL;
    new_->mapData = value;
    
    return new_;
}

// construtor da lista encadeada
Stack constructor_list()
{
    Stack new_;
    new_.head = NULL;
    new_.tail = NULL;
    new_.size = 0;

    return new_;
}

// método para adicionar ao topo da pilha
void push(Stack *linkedList, MapData * event)
{
    Node *node = constructor_node(event);

    if(linkedList->head == NULL)
    {
        linkedList->head = node;    
        linkedList->tail = node; 
        linkedList->size++;
        return;
    }
    linkedList->tail->next = node;
    node->prev = linkedList->tail;
    linkedList->tail = node;
    linkedList->size++;
}

// método para retirar da pilha o ultimo elemento
void pop(Stack *linkedList)
{
    if(linkedList->head == NULL)
        return;
    
    linkedList->size--;
    linkedList->tail = linkedList->tail->prev;
    linkedList->tail->next = NULL;
}

// método para ter acesso ao último elemento da pilha
MapData * peek(Stack *LinkedList)
{
    if (LinkedList->size == 0)
        return;
    
    return LinkedList->tail->mapData;
}



#endif