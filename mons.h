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

Pokemon initPokemon()
{
    Pokemon new_poke;
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
        strcpy(new_poke.name, token);
        token = strtok(NULL, ",");
        new_poke.hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(new_poke.atk[i].name, token);
        token = strtok(NULL, ",");
        new_poke.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        new_poke.atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);

    return new_poke;
}

Pokemon squirtle()
{
    Pokemon squirtle;

    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("../starters/squirtle/pokemon.txt", "r");
    moves = fopen("../starters/squirtle/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(squirtle.name, token);
        token = strtok(NULL, ",");
        squirtle.hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(squirtle.atk[i].name, token);
        token = strtok(NULL, ",");
        squirtle.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        squirtle.atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);

    return squirtle;
}

Pokemon charmander()
{
    Pokemon mander;

    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("../starters/charmander/pokemon.txt", "r");
    moves = fopen("../starters/charmander/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(mander.name, token);
        token = strtok(NULL, ",");
        mander.hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(mander.atk[i].name, token);
        token = strtok(NULL, ",");
        mander.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        mander.atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);

    return mander;
}

Pokemon bulbasaur()
{
    Pokemon bulba;

    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("../starters/bulbasaur/pokemon.txt", "r");
    moves = fopen("../starters/bulbasaur/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(bulba.name, token);
        token = strtok(NULL, ",");
        bulba.hp = atoi(token);
        token = strtok(NULL, ",");
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(bulba.atk[i].name, token);
        token = strtok(NULL, ",");
        bulba.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        bulba.atk[i].uses = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);

    return bulba;
}

#endif // !"mons.h"