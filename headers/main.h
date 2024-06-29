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
    int value;
    int tp_X;
    int tp_Y;
    void * entity;

} Map;

typedef struct
{

} Enemy;




typedef struct 
{
    int renderWall;
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
    Map** mapScreen;
    Map** fightScreen;
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

Objects objectsInnit(int renderPokeball, int renderEnemy, int wall)
{
    Objects objects;
    objects.renderPokeball = renderPokeball;
    objects.renderWall = wall;
    
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





    map.mapScreen = (Map**) malloc(rows * sizeof(Map**));
    for(int i=0; i<rows; i++)
    {
        map.mapScreen[i] = (Map*) malloc(collums * sizeof(Map)); 
        for(int j=0; j<collums; j++)
            map.mapScreen[i][j].value = 0;
    } 

    map.fightScreen = (Map**) malloc(ROWS * sizeof(Map**));
    for(int i=0; i<ROWS; i++)
        map.fightScreen[i] = (Map*) malloc(COLLUMS * sizeof(Map)); 
        


    return map;
}




#endif //MAIN_H