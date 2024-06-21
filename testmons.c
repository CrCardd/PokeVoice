#include <stdio.h>
#include <stdlib.h>
#include "mons.h"

int main()
{
    Pokemon *poke = malloc(sizeof(Pokemon));

    initPokemon(poke);

    printf("\nname: %s", poke->name);
    printf("\nhp: %d", poke->hp);
    printf("\nmove 1: %s", poke->atk[0].name);
    printf("\nmove 2: %s", poke->atk[1].name);
    printf("\nmove 3: %s", poke->atk[2].name);
    printf("\nmove 4: %s", poke->atk[3].name);
}