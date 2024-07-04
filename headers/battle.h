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

// Nossa batalha leva em consideração o primeiro Pokémon do Array de Pokémons
// Essa função altera o Pokémon 'Ativo'
void switchPoke(Team * team, int index)
{
    Pokemon aux;
    aux = team->pokes[0];
    team->pokes[0] = team->pokes[index];
    team->pokes[index] = aux;
}

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

int atack(Team *atacker, Team *atacked, int atack)
{
    if(atacker->pokes[0].atk[atack].uses <= 0)   // Verifica se o Pokémon possui cargas para aquele ataque
        return 0;
    
    int dmg = (atacker->pokes[0].atk[atack].dmg); // Dano base do ataque

    int mult = atack_table[atacker->pokes[0].atk->type][atacked->pokes[0].type]; // Multiplicador de dano

    dmg *= mult;

    printf("\n%s uses %s\n", atacker->pokes[0].name, atacker->pokes[0].atk[atack].name);
    
    atacker->pokes[0].atk[atack].uses--;    // Reduz a carga do ataque

    atacked->pokes[0].hp -= dmg; 

    if (atacked->pokes[0].hp <= 0 && atacked->pokes[1].hp <= 0) // Verifica se há algum Pokémon de pé na sequência
        atacked->alive = 'd';
    else if (atacked->pokes[0].hp <= 0) // Organiza com base na vida dos Pokémon quando um inimigo é derrubado
    {
        BubbleSort(atacked->pokes, 4);
    }


    return mult+1;                                              // LEMBRA DISSO CUZAO
    // 3 super
    // 1.5 pouco
     // 1 nulo
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
            atack(atacker, atacked, indexAtack);    // Função atack() como index do ataque encontrado
            return 1;
        }
    }
    
    printf("%s\n", buffer);

    return 0;
}


int item(Pokemon *poke, Bag * bag, int index)
{
    Item usedItem = useItem(bag, index); // Instancia o item já reduzindo a sua quantidade da Bag

    printf("Nome: %s\nQuantidade: %d\nTipo: %d",usedItem.name, usedItem.qtd, usedItem.type); // Info do Item

    switch (usedItem.type)  // O Efeito do Item depende de seu 'type'
    {
    case 1: // Tipo 1 recupera Vida
        if(poke->hp > 0)
        {
            poke->hp += 40;
            return 1;
        }
        else
            return 0;
        break;

    case 2: // Tipo 2 Recupera as cargas de todos os ataques
        for (int i = 0; i < 4; i++)
            poke->atk[i].uses += 10;
        return 1;
        break;

    case 3: // Tipo 3 Revive um Pokémon Caído
        if (poke->hp <= 0)
        {
            poke->hp = 30;
            return 2;   // Retorno '2' para reorganizar os pokémons
        }
        else
            return 0;
        break;       
    
    default:
        break;
    }
}

// Inimigo realiza um ataque aleatório
////////////////////////////////////// CRISTIAN
char * enemyRound(Team * you, Team * enemy)
{   
    srand(time(NULL));
    int valid;
    int indexAtack;
    do{
        indexAtack = 1 + rand()%3;
        valid = atack(enemy, you, indexAtack);
    } while (!valid);

    return enemy->pokes[0].atk[indexAtack].name;
}
//////////////////////////////////// CRISTIAN


void myRound(Team * you, Team * enemy, Bag * bag)
{
    int action;
    int indexAction;
    int indexPoke;
    printf("your round:");
    scanf(" %d", &action);  // Input do Usuário

    switch (action)
    {
    case 1:
        // Atack
        for (int i = 0; i < 4; i++)
            printf("%s\n", you->pokes[0].atk[i].name);
        
        if(!voiceAtack(you, enemy)) // Tenta utilizar o ataque com voz
        {
            int valid;

            do{
                printf("atack: ");
                scanf(" %d", &indexAction); // Caso voz falhe efetua um ataque com um input convencional
                valid = atack(you, enemy, indexAction);  // validação para caso faltem cargas                                  // ATACOU IGUAL SAPORRA
            } while (!valid);
        }
        break;

    case 2:
        // Item
        showBag(bag);   // mostra os itens da bag

        printf("item: ");
        scanf(" %d", &indexAction); // input do item selecionado
        Sleep(10);
        printf("\nPokemon: ");
        scanf(" %d", &indexPoke);   // input do pokemon para receber o item

        item(&(you->pokes[indexPoke - 1]), bag, indexAction);   // Usa o Item no Pokémon
        break;

    case 3:
        // Switch
        printf("poke: ");
        scanf(" %d", &indexAction); // Index do Pokémon a tomar a posição principal
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