#include "headers/headers.h"

int main()
{
    // Pokemon *bulba = malloc(sizeof(Pokemon));
    // Pokemon *mander = malloc(sizeof(Pokemon));

    // charmander(mander);
    // bulbasaur(bulba);

    // printf("\nname: %s", mander->name);
    // printf("\nhp: %d", mander->hp);
    // printf("\nmove 1: %s, uses %d", mander->atk[0].name, mander->atk[0].uses);
    // printf("\nmove 2: %s, uses %d", mander->atk[1].name, mander->atk[1].uses);
    // printf("\nmove 3: %s, uses %d", mander->atk[2].name, mander->atk[2].uses);
    // printf("\nmove 4: %s, uses %d", mander->atk[3].name, mander->atk[3].uses);


    // printf("\n\n");

    // atack(mander, bulba, 0);


    // printf("\nname: %s", mander->name);
    // printf("\nhp: %d", mander->hp);
    // printf("\nmove 1: %s, uses %d", mander->atk[0].name, mander->atk[0].uses);
    // printf("\n\n");
    // printf("\nname: %s", bulba->name);
    // printf("\nhp: %d", bulba->hp);

    //  Bag *bag = BagConstructor();

    // for (int i = 0; i < 4; i++)
    // {
    //     Item test  = getBag(bag, i);
    //     printf("name: %s\t", test.name);
    //     printf("qtd: %d\t", test.qtd);
    //     printf("type: %d\n\n", test.type);
    // }
    
    // printf("Usando uma potion:\n\n");

    // useItem(bag, 0);

    // for (int i = 0; i < 4; i++)
    // {
    //     Item test  = getBag(bag, i);
    //     printf("name: %s\t", test.name);
    //     printf("qtd: %d\t", test.qtd);
    //     printf("type: %d\n\n", test.type);
    // }
    
    printf("teste\n");
    Bag *bag = bagConstructor();
    printf("teste1\n");

    Team me = myTeamConstructor();
    printf("teste2\n");

    Team enemy = teamConstructor();
    printf("teste3\n");

    printf("%s \n\n", enemy.pokes[0].name);
    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", enemy.pokes[0].atk[i].name);
    }
    
    battle(&me, &enemy, bag);
    printf("teste4\n");

}
