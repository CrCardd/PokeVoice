#ifndef battle_h
#define battle_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
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

void BubbleSort(Pokemon* array, int size)
{
    Pokemon aux;

    for(int i = 0; i < size; i++){
        for (int j = 0; j + 1 < size - i; j++)
        {
            if(array[j].hp < array[j + 1].hp)
            {
                aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
    
}


void atack(Team *atacker, Team *atacked, int atack)
{
    printf("\n%s uses %s\n", atacker->pokes[0].name, atacker->pokes[0].atk[atack - 1].name);

    atacker->pokes[0].atk[atack - 1].uses--;
    atacked->pokes[0].hp -= atacker->pokes[0].atk[atack - 1].dmg;

    if (atacked->pokes[0].hp <= 0 && atacked->pokes[1].hp <= 0)
        atacked->alive = 'd';

    else if (atacked->pokes[0].hp <= 0)
    {
        BubbleSort(atacked, 4);
    }

}

int voiceAtack(Team *atacker, Team *atacked)
{
    int indexAtack = 5;
    char buffer[32];

    system("voice.exe");

    FILE * move;

    move = fopen("voice.txt", "r");
    while (fgets(buffer, sizeof(buffer), move) != NULL)
    fclose(move);

    for (int i = 0; i < 4; i++)
    {
        if(strcmp(atacker->pokes[0].atk[i].name, buffer) == 0)
        {
            indexAtack = i + 1;
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
    int indexAtack = 1 + rand()%3;

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
        
        // if(!voiceAtack(you, enemy))
        // {
            printf("atack: ");
            scanf(" %d", &indexAction);
            atack(you, enemy, indexAction);
        // }
        break;

    case 2:
        // Item
        showBag(bag);

        printf("item: ");
        scanf(" %d", &indexAction);
        Sleep(10);
        printf("\nPokemon: ");
        scanf(" %d", &indexPoke);

        item(&(you->pokes[indexPoke - 1]), bag, indexAction);
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
        printf("\nMy team:\n");
        for (int i = 0; i < 4; i++)
        {
            printf("Pokemon:%s \nLife: %d\n", you->pokes[i].name, you->pokes[i].hp);
        }
        printf("\nEnemy team: \n");
        for (int i = 0; i < 4; i++)
        {
            printf("Pokemon:%s \nLife: %d\n", enemy->pokes[i].name, enemy->pokes[i].hp);
        }
        
        if (round % 2 == 0)
            myRound(you, enemy, bag);
        else
            enemyRound(you, enemy);
        round++;
    }

    printf("cabou\n");
}

#endif