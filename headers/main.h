#ifndef MAIN_H
#define MAIN_H

#include "stack.h"
#include <stdlib.h>
#include "renderValues.h"

typedef struct 
{
    int pX;
    int pY;
    int renderValue;
    int lastCoord;

} Player;


// typedef struct
// {
//     int value;
//     int tp_X;
//     int tp_Y;
//     void * entity;

// } Map;


// typedef struct
// {
//     Map** map;
//     int rows;
//     int collums;
//     Map** options;
// } MapData;


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
    Stack stackEvents;
    MapData mapScreen;
    MapData fightScreen;

    MapData options;
    MapData bag;
    Player playerActions;

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
    player.lastCoord = 0;
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


Map** mapInnit(int rows, int collums)
{
    Map **map = malloc(rows * sizeof(Map*));
    for(int i=0; i<rows; i++)
    {
        map[i] = malloc(collums * sizeof(Map));
        for(int j=0; j<collums; j++)
            map[i][j].value = 0;
    }

    return map;
}

MapData mapDataInnit(int rows, int collums)
{
    MapData mapData;
    mapData.collums = collums;
    mapData.rows = rows;
    mapData.map = mapInnit(rows,collums);


    return mapData;
}



Room gameInnit(int rows, int collums, Player player,Objects objects)
{
    Room map;
    map.player = player;


    map.objects = objects;
    map.screenModes = screenModesInnit();

    map.mapScreen = mapDataInnit(rows,collums);
    map.fightScreen = mapDataInnit(rows,collums);

    map.options = mapDataInnit(2,2);   //

    map.options.map[0][0].tp_X = 2878;
    map.options.map[0][0].tp_Y = 3768;

    map.options.map[0][1].tp_X = 2900;
    map.options.map[0][1].tp_Y = 3790;
    
    map.options.map[1][0].tp_X = 3826;
    map.options.map[1][0].tp_Y = 4716;

    map.options.map[1][1].tp_X = 3848;
    map.options.map[1][1].tp_Y = 4738; 


    map.stackEvents = constructor_list();
    push(&map.stackEvents, map.mapScreen);

    return map;
}




#endif //MAIN_H