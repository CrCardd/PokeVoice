#include "headers/headers.h"

int main()
{
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
