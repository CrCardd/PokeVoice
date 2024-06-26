#include <stdio.h>
#include <stdlib.h>
#include "mons.h"
#include "linkedList.h"

int main()
{
    // Pokemon *bulba = malloc(sizeof(Pokemon));
    // Pokemon *mander = malloc(sizeof(Pokemon));

    // charmander(mander);
    // bulbasaur(bulba);

    // printf("\nname: %s", mander->name);
    // printf("\nhp: %d", mander->hp);
    // printf("\nmove 1: %s, uses %d", mander->atk[0].name, mander->atk[0].uses);
    // printf("\nmove 2: %s, uses %d", mander->atk[1].name, mander->atk[1].uses);
    // printf("\nmove 3: %s, uses %d", mander->atk[2].name, mander->atk[2].uses);
    // printf("\nmove 4: %s, uses %d", mander->atk[3].name, mander->atk[3].uses);


    // printf("\n\n");

    // atack(mander, bulba, 0);


    // printf("\nname: %s", mander->name);
    // printf("\nhp: %d", mander->hp);
    // printf("\nmove 1: %s, uses %d", mander->atk[0].name, mander->atk[0].uses);
    // printf("\n\n");
    // printf("\nname: %s", bulba->name);
    // printf("\nhp: %d", bulba->hp);


    Item *potion = malloc(sizeof(Item));
    strcpy(potion->name, "Potion");
    potion->qtd = 5;
    potion->type = 1;

    LinkedList *bag = LinkedListConstructor();

    addlist(bag, potion);

    Item teste = getList(bag, 0);

    printf("Nome: %s\nQuantidade: %d\nTipo: %d",teste.name, teste.qtd, teste.type);

}
