#ifndef MOVES_H 
#define MOVES_H 
 
#include <windows.h>
#include "keycodes.h"
#include "main.h"
#include"renderValues.h"

int up;
int down;
int right;
int left;
int interact;

int lastCoord = 0;

void checkMove(Room * game, Map** matrix)
{
    //COLISON
    up    = (game->mapScreen[game->player.pY-1][game->player.pX].value != game->objects.renderWall && game->player.pY > 0) ? 1 : 0;
    down  = (game->mapScreen[game->player.pY+1][game->player.pX].value != game->objects.renderWall && game->player.pY < game->rows-1) ? 1 : 0;
    left  = (game->mapScreen[game->player.pY][game->player.pX-1].value != game->objects.renderWall && game->player.pX > 0) ? 1 : 0;
    right = (game->mapScreen[game->player.pY][game->player.pX+1].value != game->objects.renderWall && game->player.pX < game->collums-1) ? 1 : 0;


    //WALK
    game->mapScreen[game->player.pY][game->player.pX].value = lastCoord;

    if(GetAsyncKeyState(VK_W) && up)
        game->player.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        game->player.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        game->player.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        game->player.pX++;

    lastCoord = game->mapScreen[game->player.pY][game->player.pX].value;
    game->mapScreen[game->player.pY][game->player.pX].value = game->player.renderValue;

    Sleep(100);
}




void checkInteract(Room* game)
{
    interact = 0;

    up    = game->mapScreen[game->player.pY-1][game->player.pX].value;
    down  = game->mapScreen[game->player.pY+1][game->player.pX].value;
    right = game->mapScreen[game->player.pY][game->player.pX+1].value;
    left  = game->mapScreen[game->player.pY][game->player.pX-1].value;

    if(GetAsyncKeyState(VK_ENTER))
    {
        if(up == game->objects.renderPokeball)  //IF ITEM UP
        {
            game->mapScreen[game->player.pY-1][game->player.pX].value = 0;
            interact = 1;
        }

        if(down == game->objects.renderPokeball) //IF ITEM DOWN
        {
            game->mapScreen[game->player.pY+1][game->player.pX].value = 0;
            interact = 1;
        }

        if(right == game->objects.renderPokeball) //IF ITEM RIGHT
        {
            game->mapScreen[game->player.pY][game->player.pX+1].value = 0;
            interact = 1;
        }

        if(left == game->objects.renderPokeball) //IF ITEM LEFT
        {
            game->mapScreen[game->player.pY][game->player.pX-1].value = 0;
            interact = 1;
        }

        if(interact)
        {
            //Trampo do Sampaio
        }

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
            game->mapScreen[game->player.pY-1][game->player.pX].value = 0;
            interact = 1;
        }

        if(down == enemy) //IF ITEM DOWN
        {
            game->mapScreen[game->player.pY+1][game->player.pX].value = 0;
            interact = 1;
        }

        if(right == enemy) //IF ITEM RIGHT
        {
            game->mapScreen[game->player.pY][game->player.pX+1].value = 0;
            interact = 1;
        }

        if(left == enemy) //IF ITEM LEFT
        {
            game->mapScreen[game->player.pY][game->player.pX-1].value = 0;
            interact = 1;
        }

        if(interact)
        {
            game->screenModes.Map = 0;
            game->screenModes.Fight = 1;
        }
    }
}









#endif