#ifndef team_h
#define team_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bag.h"
#include "mons.h"

typedef struct Team
{
    Pokemon pokes[6];
    int status[6];
    char alive;
} Team;

Team teamConstructor()
{
    Team new_team;

    new_team.alive = 'a';
    for (int i = 0; i < 4; i++)
    {
        new_team.pokes[i] = initPokemon();
        new_team.status[i] = 1;
    }

    return new_team;
}

Team myTeamConstructor()
{
    Team new_team ;

    new_team.alive = 'd';
    new_team.pokes[0] = charmander();
    new_team.pokes[1] = squirtle();
    new_team.pokes[2] = bulbasaur();

    for (int i = 0; i < 4; i++)
        new_team.status[i] = 1;

    return new_team;
}

#endif