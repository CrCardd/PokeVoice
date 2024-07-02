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
    Map lastCoord;

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
    int renderHole;
    int renderStep;
} Objects;



typedef struct 
{
    int Map;
    int SecondMap;
    int Fight;
} ScreenModes;


typedef struct 
{
    Stack stackEvents;
    MapData mapScreen;
    MapData secondMapScreen;
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
    screenModes.SecondMap = 0;

    return screenModes;
}


Player playerInnit(int renderValue, int y, int x)
{
    Player player;
    player.pX = x;
    player.pY = y;
    player.renderValue = renderValue;
    player.lastCoord.value = 0;
    return player;
}

Objects objectsInnit(int renderPokeball, int renderEnemy, int wall, int hole, int step)
{
    Objects objects;
    objects.renderPokeball = renderPokeball;
    objects.renderWall = wall;
    objects.renderEnemy = renderEnemy;
    objects.renderHole = hole;
    objects.renderStep = step;

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
    mapData.screenUpdated = 1;

    return mapData;
}


MapData optionsInnit()
{
    MapData options;
    options = mapDataInnit(2,2);

    options.map[0][0].tp_X = 2878;
    options.map[0][0].tp_Y = 3768;
    options.map[0][0].entity = "Fight";

    options.map[0][1].tp_X = 2900;
    options.map[0][1].tp_Y = 3790;
    options.map[0][1].entity = "Bag";
    
    options.map[1][0].tp_X = 3826;
    options.map[1][0].tp_Y = 4716;
    options.map[1][0].entity = "Poke";

    options.map[1][1].tp_X = 3848;
    options.map[1][1].tp_Y = 4738;
    options.map[1][1].entity = "Run";

    // options.map[0][0].entity 

    return options;
}



Room gameInnit(int rows, int collums, Player player,Objects objects)
{
    Room map;
    map.player = player;


    map.objects = objects;
    map.screenModes = screenModesInnit();

    map.mapScreen = mapDataInnit(rows,collums);
    map.secondMapScreen = mapDataInnit(rows,collums);
    map.fightScreen = mapDataInnit(rows,collums);

    map.options = optionsInnit();   

    map.stackEvents = constructor_list();

    return map;
}


void screenOff(MapData * map)
{
    map->screenUpdated = 0;
}
void screenOn(MapData * map)
{
    map->screenUpdated = 1;
}




#endif //MAIN_H