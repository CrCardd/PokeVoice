#ifndef team_h
#define team_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bag.h"
#include "mons.h"

typedef struct Team
{
    Pokemon pokes[7];
    char alive;
} Team;

Team teamConstructor()
{
    Team new_team;

    new_team.alive = 'a';
    for (int i = 0; i < 4; i++)
        new_team.pokes[i] = initPokemon();
    
    return new_team;
}

Team myTeamConstructor()
{
    Team new_team ;

    new_team.alive = 'a';
    new_team.pokes[0] = charmander();
    new_team.pokes[1] = squirtle();
    new_team.pokes[2] = bulbasaur();

    return new_team;
}

#endif