#ifndef MOVES_H 
#define MOVES_H 
 
#include <windows.h>
#include "keycodes.h"
#include "stack.h"
#include "main.h"
#include"renderValues.h"
#include "buildMap.h"



int up;
int down;
int right;
int left;


void checkMove(Room * game, MapData * screen)
{  

    //COLISON
    up    = (game->player.pY > 0 && screen->map[game->player.pY-1][game->player.pX].value != game->objects.renderWall && screen->map[game->player.pY-1][game->player.pX].value != game->objects.renderStep) ? 1 : 0;
    down  = (game->player.pY < screen->rows-1 && screen->map[game->player.pY+1][game->player.pX].value != game->objects.renderWall) ? 1 : 0;
    left  = (game->player.pX > 0 && screen->map[game->player.pY][game->player.pX-1].value != game->objects.renderWall) ? 1 : 0;
    right = (game->player.pX < screen->collums-1 && screen->map[game->player.pY][game->player.pX+1].value != game->objects.renderWall) ? 1 : 0;



    
    //WALK
    screen->map[game->player.pY][game->player.pX] = game->player.lastCoord;

    if(GetAsyncKeyState(VK_W) && up)
        game->player.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        game->player.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        game->player.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        game->player.pX++;

    

    game->player.lastCoord = screen->map[game->player.pY][game->player.pX];
    screen->map[game->player.pY][game->player.pX].value = game->player.renderValue;

    Sleep(100);
}


int selectOption(MapData * mapData)
{ 
    //COLISON
    up    = (mapData->selectOptions.actions.pY != 0) ? 1 : 0;
    down  = (mapData->selectOptions.actions.pY != mapData->selectOptions.rows-1) ? 1 : 0;
    left  = (mapData->selectOptions.actions.pX != 0) ? 1 : 0;
    right = (mapData->selectOptions.actions.pX != mapData->selectOptions.collums-1) ? 1 : 0;

    
    //CHOOSE
    buildSquare(mapData->map,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optY,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optX,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optY_,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optX_,0);

    if(GetAsyncKeyState(VK_W) && up)
        mapData->selectOptions.actions.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        mapData->selectOptions.actions.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        mapData->selectOptions.actions.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        mapData->selectOptions.actions.pX++;
    else if(GetAsyncKeyState(VK_ESC))
        return -10;
    


    buildSquare(mapData->map,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optY,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optX,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optY_,mapData->selectOptions.options[mapData->selectOptions.actions.pY][mapData->selectOptions.actions.pX].optX_,1);
    Sleep(100);

    //     if((char *)mapData->selectOptions.options.map[mapData->selectOptions.playerActions.pY][mapData->selectOptions.playerActions.pX].entity == "Run")
    //     {
    //         pop(&mapData->selectOptions.stackEvents);
    //         mapData->selectOptions.screenModes.Fight = 0;
    //         mapData->selectOptions.screenModes.Map = 1;
    //         buildSquare(mapData->selectOptions.fightScreen.map,coordUp_Y,coordUp_X,coordDown_Y,coordDown_X,0);
    //         screenOn(&mapData->selectOptions.mapScreen);
    //         Sleep(100);
    //     }
    // }
    if(GetAsyncKeyState(VK_ENTER))
        return mapData->selectOptions.actions.pY * mapData->selectOptions.collums + mapData->selectOptions.actions.pX;
    else
        return -1;

}


int checkInteract(Room * game, MapData * screen, int entity, int put)
{
    int interact = 0;


    up    = screen->map[game->player.pY-1][game->player.pX].value;
    down  = screen->map[game->player.pY+1][game->player.pX].value;
    right = screen->map[game->player.pY][game->player.pX+1].value;
    left  = screen->map[game->player.pY][game->player.pX-1].value;

    if(GetAsyncKeyState(VK_ENTER))
    {
        if(up == entity)  //IF ITEM UP
        {
            screen->map[game->player.pY-1][game->player.pX].value = put;
            interact = 1;
        }

        if(down == entity) //IF ITEM DOWN
        {
            screen->map[game->player.pY+1][game->player.pX].value = put;
            interact = 1;
        }

        if(right == entity) //IF ITEM RIGHT
        {
            screen->map[game->player.pY][game->player.pX+1].value = put;
            interact = 1;
        }

        if(left == entity) //IF ITEM LEFT
        {
            screen->map[game->player.pY][game->player.pX-1].value = put;
            interact = 1;
        }
    }
    return interact;
}


void checkHole(Room * game)
{
    if(GetAsyncKeyState(VK_ENTER) && game->player.lastCoord.value == game->objects.renderHole)
    {
        if(game->screenModes.Map)
        {
            game->mapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;
            push(&game->stackEvents,&game->secondMapScreen);
            game->screenModes.Map = 0;
            game->screenModes.SecondMap = 1;
            game->player.lastCoord = game->secondMapScreen.map[game->player.pY][game->player.pX];
            Sleep(100);
        }
        else if(game->screenModes.SecondMap)
        {
            game->secondMapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;
            pop(&game->stackEvents);
            game->screenModes.Map = 1;
            game->screenModes.SecondMap = 0;
            game->player.lastCoord = game->mapScreen.map[game->player.pY][game->player.pX];
            Sleep(100);
        }

        



    }
}


void checkEnemy(Room * game)
{

    int interact = checkInteract(game, &game->mapScreen,game->objects.renderEnemy,game->objects.renderEnemy);

    if(GetAsyncKeyState(VK_ENTER) && interact)
    {


        push(&game->stackEvents, &game->fightScreen);

        game->fightScreen.selectOptions.actions = playerInnit(0,0,0);

        game->screenModes.Fight = 1;
        game->screenModes.Map = 0;
    }   
    
}


//OPTIMIZE FUNCTION
// void checkScreenUpdate(MapData * map)
// {
//     if(GetAsyncKeyState(VK_W) || GetAsyncKeyState(VK_A) || GetAsyncKeyState(VK_S) || GetAsyncKeyState(VK_D) || GetAsyncKeyState(VK_ENTER))
//         screenOn(map);
//     else
//         screenOff(map);
// }


#endif