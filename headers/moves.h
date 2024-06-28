#ifndef MOVES_H 
#define MOVES_H 
 
#include <windows.h>
#include "keycodes.h"
#include "main.h"


#include <stdio.h>


int lastCoord = 0;
void checkWalk(Map* game)
{
    //COLISON
    int up    = (game->map[game->player.pY-1][game->player.pX] != game->renderWall) ? 1 : 0;
    int down  = (game->map[game->player.pY+1][game->player.pX] != game->renderWall) ? 1 : 0;
    int right = (game->map[game->player.pY][game->player.pX+1] != game->renderWall) ? 1 : 0;
    int left  = (game->map[game->player.pY][game->player.pX-1] != game->renderWall) ? 1 : 0;


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




void checkInteract(Map* game)
{
    int up    = game->map[game->player.pY-1][game->player.pX];
    int down  = game->map[game->player.pY+1][game->player.pX];
    int right = game->map[game->player.pY][game->player.pX+1];
    int left  = game->map[game->player.pY][game->player.pX-1];

    if(GetAsyncKeyState(VK_R))
    {
        if(up == game->renderPokeball)  //IF ITEM UP
        {
            game->map[game->player.pY-1][game->player.pX] = 0;

        }

        if(down == game->renderPokeball) //IF ITEM DOWN
        {
            game->map[game->player.pY+1][game->player.pX] = 0;

        }

        if(right == game->renderPokeball) //IF ITEM RIGHT
        {
            game->map[game->player.pY][game->player.pX+1] = 0;

        }

        if(left == game->renderPokeball) //IF ITEM LEFT
        {
            game->map[game->player.pY][game->player.pX-1] = 0;

        }

    }

}






#endif