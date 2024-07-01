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


void checkMove(Room * game)
{  

    //COLISON
    up    = (game->player.pY > 0 && game->mapScreen.map[game->player.pY-1][game->player.pX].value != game->objects.renderWall ) ? 1 : 0;
    down  = (game->player.pY < game->mapScreen.rows-1 && game->mapScreen.map[game->player.pY+1][game->player.pX].value != game->objects.renderWall) ? 1 : 0;
    left  = (game->player.pX > 0 && game->mapScreen.map[game->player.pY][game->player.pX-1].value != game->objects.renderWall) ? 1 : 0;
    right = (game->player.pX < game->mapScreen.collums-1 && game->mapScreen.map[game->player.pY][game->player.pX+1].value != game->objects.renderWall) ? 1 : 0;



    
    //WALK
    game->mapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;

    if(GetAsyncKeyState(VK_W) && up)
    {
        game->player.pY--;
        // game->mapScreen.screenUpdated = 1;
    }
    else if(GetAsyncKeyState(VK_S) && down)
    {
        game->player.pY++;
        // game->mapScreen.screenUpdated = 1;
    }
    else if(GetAsyncKeyState(VK_A) && left)
    {
        game->player.pX--;
        // game->mapScreen.screenUpdated = 1;
    }
    else if(GetAsyncKeyState(VK_D) && right)
    {
        game->player.pX++;
        // game->mapScreen.screenUpdated = 1;
    }
    else
    {
        // game->mapScreen.screenUpdated = 0;
    }

    

    game->player.lastCoord = game->mapScreen.map[game->player.pY][game->player.pX];
    game->mapScreen.map[game->player.pY][game->player.pX].value = game->player.renderValue;

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

    if(GetAsyncKeyState(VK_ENTER))
    {
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
        }
    }

    

    Sleep(100);
}


int checkInteract(Room* game, int entity, int put)
{
    int interact = 0;


    up    = game->mapScreen.map[game->player.pY-1][game->player.pX].value;
    down  = game->mapScreen.map[game->player.pY+1][game->player.pX].value;
    right = game->mapScreen.map[game->player.pY][game->player.pX+1].value;
    left  = game->mapScreen.map[game->player.pY][game->player.pX-1].value;

    if(GetAsyncKeyState(VK_ENTER))
    {
        if(up == entity)  //IF ITEM UP
        {
            game->mapScreen.map[game->player.pY-1][game->player.pX].value = put;
            interact = 1;
        }

        if(down == entity) //IF ITEM DOWN
        {
            game->mapScreen.map[game->player.pY+1][game->player.pX].value = put;
            interact = 1;
        }

        if(right == entity) //IF ITEM RIGHT
        {
            game->mapScreen.map[game->player.pY][game->player.pX+1].value = put;
            interact = 1;
        }

        if(left == entity) //IF ITEM LEFT
        {
            game->mapScreen.map[game->player.pY][game->player.pX-1].value = put;
            interact = 1;
        }
    }
    return interact;
}


void checkHole(Room * game)
{
    if(GetAsyncKeyState(VK_ENTER) && game->player.lastCoord.value == game->objects.renderHole)
    {
        game->mapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;
        game->player.pX = game->player.lastCoord.tp_X;
        game->player.pY = game->player.lastCoord.tp_Y;
        game->player.lastCoord = game->mapScreen.map[game->player.pY][game->player.pX];
    }
}


void checkEnemy(Room * game)
{

    int interact = checkInteract(game,game->objects.renderEnemy,game->objects.renderEnemy);

    if(GetAsyncKeyState(VK_ENTER) && interact)
    {


        push(&game->stackEvents, &game->fightScreen);
        game->screenModes.Fight = 1;

        game->playerActions = playerInnit(0,0,0);
        game->screenModes.Map = 0;
    }   
    
}









#endif