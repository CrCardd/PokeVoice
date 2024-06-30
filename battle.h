#ifndef battle_h
#define battle_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bag.h"
#include "mons.h"
#include "team.h"

void switchPoke(Team * team, int index)
{
    Pokemon aux;
    team->pokes[0] = aux;
    team->pokes[0] = team->pokes[index];
    team->pokes[index] = team->pokes[0];
}


void quickSort(Team * team, int Start, int End)
{
    if(Start >= End)
        return;

    int Pivot = team->pokes[End].hp;
    int i = Start;
  
    for(int j = Start; j <= End; ++j)
    {
        if(team->pokes[j].hp < Pivot)
        {
            Pokemon aux = team->pokes[i];
            team->pokes[i] = team->pokes[j];
            team->pokes[j] = aux;
            ++i;
        }
    }
    
    Pokemon aux = team->pokes[i];
    team->pokes[i] = team->pokes[End];
    team->pokes[End] = aux;

    quickSort(team, Start, i - 1);
    quickSort(team, i + 1, End);
}


void atack(Team *atacker, Team *atacked, int atack)
{
    printf("\n%s uses %s\n", atacker->pokes[0].name, atacker->pokes[0].atk[atack].name);

    atacker->pokes[0].atk[atack].uses--;
    atacked->pokes[0].hp -= atacker->pokes[0].atk[atack].dmg;

    if (atacked->pokes[0].hp <= 0 && atacked->pokes[1].hp <= 0)
        atacked->alive = 'd';

    else if (atacked->pokes[0].hp <= 0)
    {
        quickSort(atacked, 0, 5);
    }

}

int voiceAtack(Team *atacker, Team *atacked)
{
    int indexAtack = 5;
    char buffer[32];
    // printf("Hearing...\n");
    // system("./output/voice.exe");
    system("voice.exe");

    FILE * move;

    // move = fopen("./output/voice.txt", "r");
    move = fopen("voice.txt", "r");
    while (fgets(buffer, sizeof(buffer), move) != NULL)
    fclose(move);

    for (int i = 0; i < 4; i++)
    {
        if(strcmp(atacker->pokes[0].atk[i].name, buffer) == 0)
        {
            indexAtack = i;
            atack(atacker, atacked, indexAtack);
            return 1;
        }
    }
    
    printf("%s\n", buffer);
    return 0;
}


void item(Pokemon *poke, Bag * bag, int index)
{
    Item usedItem = useItem(bag, index);

    printf("Nome: %s\nQuantidade: %d\nTipo: %d",usedItem.name, usedItem.qtd, usedItem.type);

    switch (usedItem.type)
    {
    case 1:
        poke->hp += 30;
        break;

    case 2:
        for (int i = 0; i < 4; i++)
            poke->atk[i].uses += 10;
        break;

    case 3:
        if (poke->hp <= 0)
            poke->hp = 30;
        break;       
    
    default:
        break;
    }
}


void enemyRound(Team * you, Team * enemy)
{   

    srand(time(NULL));
    int indexAtack = rand()%3;

    printf("enemy atack: ");

    atack(enemy, you, indexAtack);
}


void myRound(Team * you, Team * enemy, Bag * bag)
{
    int action;
    int indexAction;
    int indexPoke;
    printf("your round:");
    scanf(" %d", &action);

    switch (action)
    {
    case 1:
        // Atack
        //implement voice atack
        for (int i = 0; i < 4; i++)
            printf("%s\n", you->pokes[0].atk[i].name);
        
        if(!voiceAtack(you, enemy))
        {
            printf("atack: ");
            scanf(" %d", &indexAction);
            atack(you, enemy, indexAction);
        }
        break;

    case 2:
        // Item
        printf("item: ");
        scanf(" %d\n", &indexAction);
        printf("Pokemon: ");
        scanf(" %d\n", &indexPoke);
        item(&(you->pokes[indexPoke]), bag, indexAction);
        break;

    case 3:
        // Switch
        printf("poke: ");
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


void battle(Team * you, Team * enemy, Bag * bag)
{
    srand(time(NULL));
    int round = 0;

    printf("me %c , enemy %c\n", you->alive, enemy->alive);

    while (you->alive == 'a' && enemy->alive == 'a')
    {
        if (round % 2 == 0)
            myRound(you, enemy, bag);
        else
            enemyRound(you, enemy);
        round++;
    }

    printf("cabou\n");
}

#endif