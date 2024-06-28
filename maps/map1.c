/*
gcc maps/map1.c -o maps/map1.exe -l gdi32 -l msimg32
*/

#include "../headers/headers.h"

#include "map1.h"

int main()
{
    pthread_t showMapThreads,checkWalkThreads;

    configureTerminal();
    
    Player player = playerInnit(PLAYER,2,2);
    Map map = gameInnit(ROWS,COLLUMS, player, WALLS,POKEBALL);
    mapInnit(&map);

    map.map[8][8] = 3;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&showMapThreads, NULL, actionsThread, (void*)&map);
    pthread_create(&showMapThreads, NULL, showMapThread, (void*)&map); 
    pthread_join(checkWalkThreads, NULL);
    pthread_join(showMapThreads, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}

