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
void checkWalk(Room* game)
{
    //COLISON
    for(int i=0; i<QTDWALLS; i++)
    {
        up    = (game->map[game->player.pY-1][game->player.pX] != game->objects.renderWalls[i]) ? 1 : 0;
        down  = (game->map[game->player.pY+1][game->player.pX] != game->objects.renderWalls[i]) ? 1 : 0;
        right = (game->map[game->player.pY][game->player.pX+1] != game->objects.renderWalls[i]) ? 1 : 0;
        left  = (game->map[game->player.pY][game->player.pX-1] != game->objects.renderWalls[i]) ? 1 : 0;
    }


    //WALK
    game->map[game->player.pY][game->player.pX] = lastCoord;

    if(GetAsyncKeyState(VK_W) && game->player.pY && up)
        game->player.pY--;
    else if(GetAsyncKeyState(VK_S) && game->player.pY+1<game->rows && down)
        game->player.pY++;
    else if(GetAsyncKeyState(VK_A) && game->player.pX && left)
        game->player.pX--;
    else if(GetAsyncKeyState(VK_D) && game->player.pX+1<game->collums && right)
        game->player.pX++;

    lastCoord = game->map[game->player.pY][game->player.pX];
    game->map[game->player.pY][game->player.pX] = game->player.renderValue;

    Sleep(100);
}




void checkInteract(Room* game)
{
    interact = 0;

    up    = game->map[game->player.pY-1][game->player.pX];
    down  = game->map[game->player.pY+1][game->player.pX];
    right = game->map[game->player.pY][game->player.pX+1];
    left  = game->map[game->player.pY][game->player.pX-1];

    if(GetAsyncKeyState(VK_R))
    {
        if(up == game->objects.renderPokeball)  //IF ITEM UP
        {
            game->map[game->player.pY-1][game->player.pX] = 0;
            interact = 1;
        }

        if(down == game->objects.renderPokeball) //IF ITEM DOWN
        {
            game->map[game->player.pY+1][game->player.pX] = 0;
            interact = 1;

        }

        if(right == game->objects.renderPokeball) //IF ITEM RIGHT
        {
            game->map[game->player.pY][game->player.pX+1] = 0;
            interact = 1;

        }

        if(left == game->objects.renderPokeball) //IF ITEM LEFT
        {
            game->map[game->player.pY][game->player.pX-1] = 0;
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

    if()
        if(up == enemy)  //IF ITEM UP
        {
            game->map[game->player.pY-1][game->player.pX] = 0;
            interact = 1;
        }

        if(down == enemy) //IF ITEM DOWN
        {
            game->map[game->player.pY+1][game->player.pX] = 0;
            interact = 1;
        }

        if(right == enemy) //IF ITEM RIGHT
        {
            game->map[game->player.pY][game->player.pX+1] = 0;
            interact = 1;
        }

        if(left == enemy) //IF ITEM LEFT
        {
            game->map[game->player.pY][game->player.pX-1] = 0;
            interact = 1;
        }

        if(interact)
        {
            //Trampo do Cristian

        }

}









#endif