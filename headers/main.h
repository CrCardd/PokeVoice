#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include "renderValues.h"

typedef struct 
{
    int pX;
    int pY;
    int renderValue;

} Player;





typedef struct 
{
    int renderWalls[10];
    int renderPokeball;
    int renderEnemy;
} Objects;



typedef struct 
{
    int Map;
    int Fight;
} ScreenModes;



typedef struct 
{
    int** map;
    int rows;
    int collums;
    Objects objects;
    Player player;
    ScreenModes screenModes;
} Room;



ScreenModes screenModesInnit()
{
    ScreenModes screenModes;
    screenModes.Fight = 0;
    screenModes.Map = 1;

    return screenModes;
}


Player playerInnit(int renderValue, int y, int x)
{
    Player player;
    player.pX = x;
    player.pY = y;
    player.renderValue = renderValue;
    return player;
}

Objects objectsInnit(int renderPokeball, int renderEnemy)
{
    Objects objects;
    objects.renderPokeball = renderPokeball;
    for(int i=0; i<QTDWALLS; i++)                      
        objects.renderWalls[i] = i+1;
    
    objects.renderEnemy = renderEnemy;

    return objects;
}


Room gameInnit(int rows, int collums, Player player,Objects objects)
{
    Room map;
    map.rows = rows; 
    map.collums = collums; 
    map.player = player;
    map.objects = objects;
    map.screenModes = screenModesInnit();





    map.map = (int**) malloc(rows * sizeof(int**));
    for(int i=0; i<rows; i++)
    {
        map.map[i] = (int*) malloc(collums * sizeof(int)); 
        for(int j=0; j<collums; j++)
            map.map[i][j] = 0;
    } 
        

    return map;
}







#endif //MAIN_H