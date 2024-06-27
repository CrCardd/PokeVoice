#ifndef mons_h
#define mons_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bag.h"

typedef struct Atack
{
    char name[50];
    int dmg;
    int uses;
} Atack;

typedef struct Pokemon
{
    char name[12];
    int hp;
    struct Atack atk[4];
} Pokemon;

void initPokemon(Pokemon *poke)
{
    // Escreve novos valores nos txt's
    system("pokeAPI.exe");

    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("pokemon.txt", "r");
    moves = fopen("moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(poke->name, token);
        token = strtok(NULL, ",");
        poke->hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(poke->atk[i].name, token);
        token = strtok(NULL, ",");
        poke->atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        poke->atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);
}

void squirtle(Pokemon *poke)
{
    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("../starters/squirtle/pokemon.txt", "r");
    moves = fopen("../starters/squirtle/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(poke->name, token);
        token = strtok(NULL, ",");
        poke->hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(poke->atk[i].name, token);
        token = strtok(NULL, ",");
        poke->atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        poke->atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);
}

void charmander(Pokemon *poke)
{
    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("../starters/charmander/pokemon.txt", "r");
    moves = fopen("../starters/charmander/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(poke->name, token);
        token = strtok(NULL, ",");
        poke->hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(poke->atk[i].name, token);
        token = strtok(NULL, ",");
        poke->atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        poke->atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);
}

void bulbasaur(Pokemon *poke)
{
    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("../starters/bulbasaur/pokemon.txt", "r");
    moves = fopen("../starters/bulbasaur/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(poke->name, token);
        token = strtok(NULL, ",");
        poke->hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(poke->atk[i].name, token);
        token = strtok(NULL, ",");
        poke->atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        poke->atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);
}

void atack(Pokemon *atacker, Pokemon *atacked, int atack)
{
    atacker->atk[atack].uses--;
    atacked->hp -= atacker->atk[atack].dmg;
}

void item(Pokemon *poke, Bag * bag)
{
    Item teste = useItem(bag, 0);

    printf("Nome: %s\nQuantidade: %d\nTipo: %d",teste.name, teste.qtd, teste.type);

    switch (teste.type)
    {
    case 1:
        poke->hp += 30;
        break;

    case 2:
        for (int i = 0; i < 4; i++)
            poke->atk[i].uses += 10;
        break;

    case 3:
        if (poke->hp == 0)
            poke->hp += 30;
        break;       
    
    default:
        break;
    }
}

#endif // !"mons.h"