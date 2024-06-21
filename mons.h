#ifndef mons_h
#define mons_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("../pokemon.txt", "r");
    moves = fopen("../moves.txt", "r");

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
        poke->atk[i].uses, atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);
}

#endif // !"mons.h"