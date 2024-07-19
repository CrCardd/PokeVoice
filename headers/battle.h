#ifndef battle_h
#define battle_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "bag.h"
#include "mons.h"
#include "team.h"
// Multiplicadores de dano com base nos tipos
float atack_table[18][18] = {
    {1, 1, 1, 1, 1, 0.5, 1, 0, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {2, 1, 0.5, 0.5, 1, 2, 0.5, 0, 2, 1, 1, 1, 1, 0.5, 2, 1, 2, 0.5},
    {1, 2, 1, 1, 1, 0.5, 2, 1, 0.5, 1, 1, 2, 0.5, 1, 1, 1, 1, 1},
    {1, 1, 1, 0.5, 0.5, 0.5, 1, 0.5, 0, 1, 1, 2, 1, 1, 1, 1, 1, 2},
    {1, 1, 0, 2, 1, 2, 0.5, 1, 2, 2, 1, 0.5, 2, 1, 1, 1, 1, 1},
    {1, 0.5, 2, 1, 0.5, 1, 2, 1, 0.5, 2, 1, 1, 1, 1, 2, 1, 1, 1},
    {1, 0.5, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 0.5, 1, 2, 1, 2, 1, 1, 2, 0.5},
    {0, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 1},
    {1, 1, 1, 1, 1, 2, 1, 1, 0.5, 0.5, 0.5, 1, 0.5, 1, 2, 1, 1, 2},
    {1, 1, 1, 1, 1, 0.5, 2, 1, 2, 0.5, 0.5, 2, 1, 1, 2, 0.5, 1, 1},
    {1, 1, 1, 1, 2, 2, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 0.5, 1, 1},
    {1, 1, 0.5, 0.5, 2, 2, 0.5, 1, 0.5, 0.5, 2, 0.5, 1, 1, 1, 0.5, 1, 1},
    {1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 0.5, 1, 1},
    {1, 2, 1, 2, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 0.5, 1, 1, 0, 1},
    {1, 1, 2, 1, 2, 1, 1, 1, 0.5, 0.5, 0.5, 2, 1, 1, 0.5, 2, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0.5, 1, 1, 1, 1, 1, 1, 2, 1, 0},
    {1, 0.5, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 0.5, 0.5},
    {1, 2, 1, 0.5, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 1, 2, 2, 1}
};


//Bubble Sort utilizado para reorganizar os Pokémons decrescentemente com base na vida
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

float atack(Team *atacker, Team *atacked, int atack)
{

    float dmg = (atacker->pokes[0].atk[atack].dmg); // Dano base do ataque

    float mult = atack_table[atacker->pokes[0].atk->type][atacked->pokes[0].type]; // Multiplicador de dano

    atacker->pokes[0].atk[atack].uses--;    // Reduz a carga do ataque

    dmg *= mult;

    atacked->pokes[0].hp = (atacked->pokes[0].hp - dmg <= 0) ? 0 : atacked->pokes[0].hp - dmg;

    if (atacked->pokes[0].hp <= 0 && atacked->pokes[1].hp <= 0) // Verifica se há algum Pokémon de pé na sequência
        atacked->alive = 'd';
    else if (atacked->pokes[0].hp <= 0) // Organiza com base na vida dos Pokémon quando um inimigo é derrubado
        BubbleSort(atacked->pokes, 4);

    return mult;
}

int voiceAtack(Team *atacker, Team *atacked)
{
    int indexAtack = 5;
    char buffer[32];

    system("voice.exe"); // Escreve no arquivo a fala do usuário

    FILE * move;

    move = fopen("voice.txt", "r");
    while (fgets(buffer, sizeof(buffer), move) != NULL) // guarda em um buffer o input do usuário
    fclose(move);

    for (int i = 0; i < 4; i++)
    {
        if(strcmp(atacker->pokes[0].atk[i].name, buffer) == 0)  // Compara com todos os ataques
        {
            indexAtack = i;
            return (atack(atacker, atacked, indexAtack) + 1) * 2;    // Função atack() como index do ataque encontrado
        }
    }
    

    return 0;
}


int item(Pokemon *poke, Bag * bag, int index)
{
    Item usedItem = useItem(bag, index); // Instancia o item já reduzindo a sua quantidade da Bag

     // Info do Item

    switch (usedItem.type)  // O Efeito do Item depende de seu 'type'
    {
    case 1: // Tipo 1 recupera Vida
        if(poke->hp > 0)
        {
            poke->hp = (poke->hp + 40 > poke->maxhp) ? poke->maxhp : poke->hp + 40;
            return 1;
        }
        else
            return 0;
        break;

    case 2: // Tipo 2 Recupera as cargas de todos os ataques
        for (int i = 0; i < 4; i++)
            poke->atk[i].uses = poke->atk[i].maxuses;
        return 1;
        break;

    case 3: // Tipo 3 Revive um Pokémon Caído
        if (poke->hp == 0)
        {
            poke->hp += poke->maxhp;
            return 2;   // Retorno '2' para reorganizar os pokémons
        }
        else
            return 0;
        break;       
    
    default:
        break;
    }
}

#endif