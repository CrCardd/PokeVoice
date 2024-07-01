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
    up    = (game->player.pY > 0 && screen->map[game->player.pY-1][game->player.pX].value != game->objects.renderWall ) ? 1 : 0;
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


void selectOption(Room * game)
{ 
    


    //COLISON
    up    = (game->playerActions.pY > 0 && game->options.map[game->playerActions.pY-1][game->playerActions.pX].value != game->objects.renderWall) ? 1 : 0;
    down  = (game->playerActions.pY < game->options.rows-1 && game->options.map[game->playerActions.pY+1][game->playerActions.pX].value != game->objects.renderWall) ? 1 : 0;
    left  = (game->playerActions.pX > 0 && game->options.map[game->playerActions.pY][game->playerActions.pX-1].value != game->objects.renderWall) ? 1 : 0;
    right = (game->playerActions.pX < game->options.collums-1 && game->options.map[game->playerActions.pY][game->playerActions.pX+1].value != game->objects.renderWall) ? 1 : 0;

    
    //CHOOSE
    // game->options.map[game->playerActions.pY][game->playerActions.pX].value = game->playerActions.lastCoord;
    int coordUp_Y = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_X - 1) / game->fightScreen.collums + 1;
    int coordUp_X = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_X - 1) % game->fightScreen.collums;
    int coordDown_Y = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_Y - 1) / game->fightScreen.collums + 1;
    int coordDown_X = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_Y - 1) % game->fightScreen.collums;
    buildSquare(game->fightScreen.map,coordUp_Y,coordUp_X,coordDown_Y,coordDown_X,0);

    if(GetAsyncKeyState(VK_W) && up)
        game->playerActions.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        game->playerActions.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        game->playerActions.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        game->playerActions.pX++;


    coordUp_Y = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_X - 1) / game->fightScreen.collums + 1;
    coordUp_X = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_X - 1) % game->fightScreen.collums;
    coordDown_Y = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_Y - 1) / game->fightScreen.collums + 1;
    coordDown_X = (game->options.map[game->playerActions.pY][game->playerActions.pX].tp_Y - 1) % game->fightScreen.collums;

    buildSquare(game->fightScreen.map,coordUp_Y,coordUp_X,coordDown_Y,coordDown_X,1);
    Sleep(100);

    if(GetAsyncKeyState(VK_ENTER))
    {
        screenOn(&game->fightScreen);

        if((char *)game->options.map[game->playerActions.pY][game->playerActions.pX].entity == "Fight")
        {
            
        }
        if((char *)game->options.map[game->playerActions.pY][game->playerActions.pX].entity == "Bag")
        {

        }
        if((char *)game->options.map[game->playerActions.pY][game->playerActions.pX].entity == "Poke")
        {

        }
        if((char *)game->options.map[game->playerActions.pY][game->playerActions.pX].entity == "Run")
        {
            pop(&game->stackEvents);
            game->screenModes.Fight = 0;
            game->screenModes.Map = 1;
            buildSquare(game->fightScreen.map,coordUp_Y,coordUp_X,coordDown_Y,coordDown_X,0);
            screenOn(&game->mapScreen);
            Sleep(80);
        }
    }

    

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
        // game->player.pX = game->player.lastCoord.tp_X;
        // game->player.pY = game->player.lastCoord.tp_Y;
        if(game->screenModes.Map)
        {
            game->mapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;
            push(&game->stackEvents,&game->secondMapScreen);
            game->screenModes.Map = 0;
            game->screenModes.SecondMap = 1;
            game->player.lastCoord = game->secondMapScreen.map[game->player.pY][game->player.pX];
            
        }
        else if(game->screenModes.SecondMap)
        {
            game->secondMapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;
            pop(&game->stackEvents);
            game->screenModes.Map = 1;
            game->screenModes.SecondMap = 0;
            game->player.lastCoord = game->mapScreen.map[game->player.pY][game->player.pX];
        }

        



    }
}


void checkEnemy(Room * game)
{

    int interact = checkInteract(game, &game->mapScreen,game->objects.renderEnemy,game->objects.renderEnemy);

    if(GetAsyncKeyState(VK_ENTER) && interact)
    {


        push(&game->stackEvents, &game->fightScreen);

        game->playerActions = playerInnit(0,0,0);

        game->screenModes.Fight = 1;
        game->screenModes.Map = 0;
    }   
    
}


void checkScreenUpdate(MapData * map)
{
    if(GetAsyncKeyState(VK_W) || GetAsyncKeyState(VK_A) || GetAsyncKeyState(VK_S) || GetAsyncKeyState(VK_D) || GetAsyncKeyState(VK_ENTER))
        screenOn(map);
    else
        screenOff(map);

}









#endif