#ifndef MOVES_H 
#define MOVES_H 
 
#include <windows.h>
#include "keycodes.h"
#include "stack.h"
#include "main.h"
#include"renderValues.h"


int up;
int down;
int right;
int left;
int interact;

void checkMove(Room * game, MapData mapData)
{
    
    //COLISON
    up    = (game->player.pY > 0 && mapData.map[game->player.pY-1][game->player.pX].value != game->objects.renderWall) ? 1 : 0;
    down  = (game->player.pY < mapData.rows-1 && mapData.map[game->player.pY+1][game->player.pX].value != game->objects.renderWall) ? 1 : 0;
    left  = (game->player.pX > 0 && mapData.map[game->player.pY][game->player.pX-1].value != game->objects.renderWall) ? 1 : 0;
    right = (game->player.pX < mapData.collums-1 && mapData.map[game->player.pY][game->player.pX+1].value != game->objects.renderWall) ? 1 : 0;

    
    //WALK
    mapData.map[game->player.pY][game->player.pX].value = game->player.lastCoord;

    if(GetAsyncKeyState(VK_W) && up)
        game->player.pY--;
    else if(GetAsyncKeyState(VK_S) && down)
        game->player.pY++;
    else if(GetAsyncKeyState(VK_A) && left)
        game->player.pX--;
    else if(GetAsyncKeyState(VK_D) && right)
        game->player.pX++;

    game->player.lastCoord = mapData.map[game->player.pY][game->player.pX].value;
    mapData.map[game->player.pY][game->player.pX].value = game->player.renderValue;

    Sleep(100);
}




void checkInteract(Room* game)
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



void checkEnemy(Room * game)
{
    int enemy = game->objects.renderEnemy;
    interact = 0;

    if(GetAsyncKeyState(VK_ENTER))
    {
        if(up == enemy)  //IF ITEM UP
        {
            game->mapScreen.map[game->player.pY-1][game->player.pX].value = 0;
            interact = 1;
        }

        if(down == enemy) //IF ITEM DOWN
        {
            game->mapScreen.map[game->player.pY+1][game->player.pX].value = 0;
            interact = 1;
        }

        if(right == enemy) //IF ITEM RIGHT
        {
            game->mapScreen.map[game->player.pY][game->player.pX+1].value = 0;
            interact = 1;
        }

        if(left == enemy) //IF ITEM LEFT
        {
            game->mapScreen.map[game->player.pY][game->player.pX-1].value = 0;
            interact = 1;
        }

        if(interact)
        {
            push(&game->stackEvents, game->fightScreen);
        }
    }
}









#endif