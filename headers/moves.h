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
int interact;


void checkMove(Room * game)
{  

    //COLISON
    up    = (game->player.pY > 0 && game->mapScreen.map[game->player.pY-1][game->player.pX].value != game->objects.renderWall) ? 1 : 0;
    down  = (game->player.pY < game->mapScreen.rows-1 && game->mapScreen.map[game->player.pY+1][game->player.pX].value != game->objects.renderWall) ? 1 : 0;
    left  = (game->player.pX > 0 && game->mapScreen.map[game->player.pY][game->player.pX-1].value != game->objects.renderWall) ? 1 : 0;
    right = (game->player.pX < game->mapScreen.collums-1 && game->mapScreen.map[game->player.pY][game->player.pX+1].value != game->objects.renderWall) ? 1 : 0;

    
    //WALK
    game->mapScreen.map[game->player.pY][game->player.pX] = game->player.lastCoord;

    if(GetAsyncKeyState(VK_W) && up)
        game->player.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        game->player.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        game->player.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        game->player.pX++;

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




    

    Sleep(100);
}





void checkInteract(Room* game, int entity)
{
    interact = 0;


    up    = game->mapScreen.map[game->player.pY-1][game->player.pX].value;
    down  = game->mapScreen.map[game->player.pY+1][game->player.pX].value;
    right = game->mapScreen.map[game->player.pY][game->player.pX+1].value;
    left  = game->mapScreen.map[game->player.pY][game->player.pX-1].value;

    if(GetAsyncKeyState(VK_ENTER))
    {
        if(up == game->objects.renderPokeball)  //IF ITEM UP
        {
            game->mapScreen.map[game->player.pY-1][game->player.pX].value = 0;
            interact = 1;
        }

        if(down == game->objects.renderPokeball) //IF ITEM DOWN
        {
            game->mapScreen.map[game->player.pY+1][game->player.pX].value = 0;
            interact = 1;
        }

        if(right == game->objects.renderPokeball) //IF ITEM RIGHT
        {
            game->mapScreen.map[game->player.pY][game->player.pX+1].value = 0;
            interact = 1;
        }

        if(left == game->objects.renderPokeball) //IF ITEM LEFT
        {
            game->mapScreen.map[game->player.pY][game->player.pX-1].value = 0;
            interact = 1;
        }

        if(interact)
        {
            //Trampo do Sampaio
        }

    }

}

void checkHole(Room * game)
{
    if(GetAsyncKeyState(VK_ENTER) && game->player.lastCoord.value == game->objects.renderHole)
    {
        game->mapScreen.map;
        game->player.pX = game->player.lastCoord.tp_X;
        game->player.pY = game->player.lastCoord.tp_Y;
    }
}



void checkEnemy(Room * game)
{
    int enemy = game->objects.renderEnemy;
    interact = 0;

    if(GetAsyncKeyState(VK_ENTER))
    {
        if(up == enemy)  //IF ITEM UP
        {
            // game->mapScreen.map[game->player.pY-1][game->player.pX].value = 0;
            interact = 1;
        }

        if(down == enemy) //IF ITEM DOWN
        {
            // game->mapScreen.map[game->player.pY+1][game->player.pX].value = 0;
            interact = 1;
        }

        if(right == enemy) //IF ITEM RIGHT
        {
            // game->mapScreen.map[game->player.pY][game->player.pX+1].value = 0;
            interact = 1;
        }

        if(left == enemy) //IF ITEM LEFT
        {
            // game->mapScreen.map[game->player.pY][game->player.pX-1].value = 0;
            interact = 1;
        }

        if(interact)
        {
            Sleep(10000);
            push(&game->stackEvents, game->fightScreen);
            game->screenModes.Fight = 1;
            game->playerActions = playerInnit(0,0,0);
            game->screenModes.Map = 0;
        }
    }
}









#endif