#ifndef battle_h
#define battle_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "bag.h"
#include "mons.h"
#include "team.h"

int battle(Team * you, Team * enemy)
{
    srand(time(NULL));
    int round = 1;

    while (you->alive == 'a' && enemy->alive == 'a')
    {
        if (round % 2)
            myRound(&you, &enemy);
        else
            enemyRound(&you, &enemy);
    }

    round++;
}

void myRound(Team * you, Team * enemy)
{
    int action;
    int indexAction;
    scanf(" %d", &action);

    switch (action)
    {
    case 1:
        // Atack
        scanf(" %d", &indexAction);
        atack(&you->pokes[0], &enemy->pokes[0], indexAction);
        break;

    case 2:
        // Item
        scanf(" %d", &indexAction);
        break;

    case 3:
        // Switch
        scanf(" %d", &indexAction);
        switchPoke(you, indexAction);
        break;

    case 4:
        // Run
        break;
    
    default:
        break;
    }
}

void enemyRound(Team * you, Team * enemy)
{

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

void switchPoke(Team * team, int index)
{
    Pokemon aux;
    team->pokes[0] = aux;
    team->pokes[0] = team->pokes[index];
    team->pokes[index] = team->pokes[0];
}

#endif