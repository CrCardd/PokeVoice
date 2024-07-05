#ifndef mons_h
#define mons_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "bag.h"

typedef struct Atack
{
    char name[50];
    int dmg;
    int maxuses, uses;
    int type;
} Atack;

typedef struct Pokemon
{
    char name[12];
    int maxhp, hp; 
    struct Atack atk[4];
    int type;
} Pokemon;

Pokemon initPokemon()
{
    Pokemon new_poke;
    system("pokeAPI.exe");
    Sleep(0.5);

    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("pokemon.txt", "r");   // Arquivo com Nome, vida e tipo do Pokémon
    moves = fopen("moves.txt", "r");    // Arquivo com Nome, dano , cargas e tipo dos Ataques

    while (fgets(line, sizeof(line), name) != NULL) {   // Lê e popula as informações do Pokémon
        token = strtok(line, ",");
        strcpy(new_poke.name, token);
        token = strtok(NULL, ",");
        new_poke.maxhp = atoi(token);
        new_poke.hp = atoi(token);
        token = strtok(NULL, ",");
        new_poke.type = atoi(token);
    }

    while (fgets(line, sizeof(line), moves) != NULL) {  // Lê e popula as informações dos Ataques
        token = strtok(line, ","),
        strcpy(new_poke.atk[i].name, token);
        token = strtok(NULL, ",");
        new_poke.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        new_poke.atk[i].maxuses = atoi(token);
        new_poke.atk[i].uses = atoi(token);
        token = strtok(NULL, ",");
        new_poke.atk[i].type = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);

    return new_poke;
}


// Iniciais Pré-definidos
Pokemon squirtle()
{
    Pokemon squirtle;

    FILE *name;
    FILE *moves;
    char line[32];
    char *token;
    int i = 0;

    name = fopen("starters/squirtle/pokemon.txt", "r");
    moves = fopen("starters/squirtle/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(squirtle.name, token);
        token = strtok(NULL, ",");
        squirtle.maxhp = atoi(token);
        squirtle.hp = atoi(token);
        token = strtok(NULL, ",");
        squirtle.type = atoi(token);
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(squirtle.atk[i].name, token);
        token = strtok(NULL, ",");
        squirtle.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        squirtle.atk[i].maxuses = atoi(token);
        squirtle.atk[i].uses = atoi(token);
        token = strtok(NULL, ",");
        squirtle.atk[i].type = atoi(token);
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

    name = fopen("starters/charmander/pokemon.txt", "r");
    moves = fopen("starters/charmander/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(mander.name, token);
        token = strtok(NULL, ",");
        mander.maxhp = atoi(token);
        mander.hp = atoi(token);
        token = strtok(NULL, ",");
        mander.type = atoi(token);
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(mander.atk[i].name, token);
        token = strtok(NULL, ",");
        mander.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        mander.atk[i].maxuses = atoi(token);
        mander.atk[i].uses = atoi(token);
        token = strtok(NULL, ",");
        mander.atk[i].type = atoi(token);
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

    name = fopen("starters/bulbasaur/pokemon.txt", "r");
    moves = fopen("starters/bulbasaur/moves.txt", "r");

    while (fgets(line, sizeof(line), name) != NULL) {
        token = strtok(line, ",");
        strcpy(bulba.name, token);
        token = strtok(NULL, ",");
        bulba.maxhp = atoi(token);
        bulba.hp = atoi(token);
        token = strtok(NULL, ",");
        bulba.type = atoi(token);
    }

    while (fgets(line, sizeof(line), moves) != NULL) {
        token = strtok(line, ","),

        strcpy(bulba.atk[i].name, token);
        token = strtok(NULL, ",");
        bulba.atk[i].dmg = atoi(token);
        token = strtok(NULL, ",");
        bulba.atk[i].maxuses = atoi(token);
        bulba.atk[i].uses = atoi(token);
        token = strtok(NULL, ",");
        bulba.atk[i].type = atoi(token);
        i++;
    }
    fclose(name);
    fclose(moves);

    return bulba;
}

#endif // !"mons.h"