#ifndef MAIN_H
#define MAIN_H

#include "buildMap.h"
#include "stack.h"
#include <stdlib.h>
#include "renderValues.h"

#include <string.h>
#include "team.h"
#include "battle.h"




typedef struct
{
    int renderValue;
    int eY;
    int eX;
    Team team;
} Enemy;




typedef struct 
{
    int pX;
    int pY;
    int renderValue;
    Map lastCoord;
    Team team;
    void * currentEntity;

} Player;


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


struct Room
{
    Stack stackEvents;
    MapData mapScreen;
    MapData secondMapScreen;
    MapData fightScreen;
    MapData attackScreen;
    MapData bagScreen;
    MapData bagUseScreen;
    MapData PokeScreen;

    
    Objects objects;
    Player player;
    Player actions;
    ScreenModes screenModes;
};






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
    player.team = myTeamConstructor();


    //  strcpy(player.team.pokes->atk[0].name, "atk1");
    //  strcpy(player.team.pokes->atk[1].name, "atk2");
    //  strcpy(player.team.pokes->atk[2].name, "atk3");
    //  strcpy(player.team.pokes->atk[3].name, "atk4");


    return player;
}




void spawnEnemy(Map** map, int renderValue, int y, int x)
{
    Enemy * enemy = malloc(sizeof(Enemy));
    enemy->renderValue = renderValue;
    enemy->eY = y;
    enemy->eX = x;
    enemy->team = teamConstructor();

    map[y][x].value = renderValue;
    map[y][x].entity = enemy;
    
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


Options ** matrizOptionsInnit(int rows, int collums)
{
    Options ** options = malloc(rows * sizeof(Options*));
    for(int i=0; i<rows; i++)
        options[i] = malloc(collums * sizeof(Options));
    
    return options;
}


SelectOptions selectOptionsInnit(int rows, int collums)
{
    SelectOptions selectOptions;
    selectOptions.rows = rows;
    selectOptions.collums = collums;
    return selectOptions;
}


Options ** menuFightInnit()
{
    Options ** options = matrizOptionsInnit(2,2);
    

    // int arr0[] = {37,33,48,54};
    options[0][0].optY = 37;
    options[0][0].optX = 33;
    options[0][0].optY_ = 48;
    options[0][0].optX_ = 54;
    options[0][0].entity = "Fight";

    // int arr1[] = {37,55,48,76};
    options[0][1].optY = 37;
    options[0][1].optX = 55;
    options[0][1].optY_ = 48;
    options[0][1].optX_ = 76;
    options[0][1].entity = "Bag";

    // int arr2[] = {49,33,60,54};
    options[1][0].optY = 49;
    options[1][0].optX = 33;
    options[1][0].optY_ = 60;
    options[1][0].optX_ = 54;
    options[1][0].entity = "Poke";

    // int arr3[] = {49,55,60,76};
    options[1][1].optY = 49;
    options[1][1].optX = 55;
    options[1][1].optY_ = 60;
    options[1][1].optX_ = 76;
    options[1][1].entity = "Run";


    return options;
}







void selectOptionFight(Room * game, int option)
{
    switch (option)
    {
    case 0:

        // game->attackScreen.map[4][8].entity = (void*)game->player.currentEnemy->team.pokes[0].name;
        // game->attackScreen.map[30][50].entity = (void*)game->player.team.pokes[0].name;

        attackScreenConstructor(game->attackScreen.map);
        game->attackScreen.map[42][42].entity = (void*)game->player.team.pokes[0].atk[0].name;     
        game->attackScreen.map[42][42].value = MESSAGE;
        game->attackScreen.map[42][64].entity = (void*)game->player.team.pokes[0].atk[1].name;
        game->attackScreen.map[42][64].value = MESSAGE;
        game->attackScreen.map[54][42].entity = (void*)game->player.team.pokes[0].atk[2].name;
        game->attackScreen.map[54][42].value = MESSAGE;
        game->attackScreen.map[54][64].entity = (void*)game->player.team.pokes[0].atk[3].name;
        game->attackScreen.map[54][64].value = MESSAGE;
        game->actions = playerInnit(0,0,0);

        resetScreen(&game->fightScreen);

        push(&game->stackEvents, &game->attackScreen);
        Sleep(100);
        
        break;
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        pop(&game->stackEvents);
        game->screenModes.Fight = 0;
        game->screenModes.Map = 1;
        resetScreen(&game->fightScreen);
        fightScreenConstruct(game->fightScreen.map);
        Sleep(100);
        break;
    
    default:
        break;
    }
}


void selectOptionAttack(Room * game, int option)
{
    if(GetAsyncKeyState(VK_ESC))
    {
        resetScreen(&game->attackScreen);
        fightScreenConstruct(game->fightScreen.map);
        pop(&game->stackEvents);
    }
    if(option != -1)
        atack(&game->player.team, &((Enemy*)game->player.currentEntity)->team, option);
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
    map.fightScreen.selectOptions = selectOptionsInnit(2,2);
    map.fightScreen.selectOptions.options = menuFightInnit();
    map.fightScreen.func = selectOptionFight;


    map.attackScreen = mapDataInnit(rows, collums);
    map.attackScreen.selectOptions = selectOptionsInnit(2,2);
    map.attackScreen.selectOptions.options = menuFightInnit();
    map.attackScreen.func = selectOptionAttack;


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