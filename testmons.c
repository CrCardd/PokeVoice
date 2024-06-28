#include <stdio.h>
#include <stdlib.h>
#include "mons.h"

int main()
{
    char buffer[32];
    Pokemon poke = initPokemon();

    printf("\nname: %s", poke.name);
    printf("\nhp: %d", poke.hp);
    printf("\nmove 1: %s", poke.atk[0].name);
    printf("\nmove 2: %s", poke.atk[1].name);
    printf("\nmove 3: %s", poke.atk[2].name);
    printf("\nmove 4: %s", poke.atk[3].name);


    system("voice.exe");

    FILE * move;

    move = fopen("voice.txt", "r");

    while (fgets(buffer, sizeof(buffer), move) != NULL)

    fclose(move);

    printf("%s", buffer);
}
