#ifndef MOVES_H 
#define MOVES_H 
 
#include <windows.h>
#include "keycodes.h"
#include "main.h"
#include <math.h>


#include <stdio.h>


void checkWalk(Map* game)
{
    //COLISON
    int up    = (game->map[game->player.pY-1][game->player.pX] != game->renderWall) ? 1 : 0;
    int down  = (game->map[game->player.pY+1][game->player.pX] != game->renderWall) ? 1 : 0;
    int right = (game->map[game->player.pY][game->player.pX+1] != game->renderWall) ? 1 : 0;
    int left  = (game->map[game->player.pY][game->player.pX-1] != game->renderWall) ? 1 : 0;


    //WALK
    game->map[game->player.pY][game->player.pX] = 0;


    if(GetAsyncKeyState(VK_W) && game->player.pY && up)
        game->player.pY--;
    else if(GetAsyncKeyState(VK_S) && game->player.pY+1<game->rows && down)
        game->player.pY++;
    else if(GetAsyncKeyState(VK_A) && game->player.pX && left)
        game->player.pX--;
    else if(GetAsyncKeyState(VK_D) && game->player.pX+1<game->collums && right)
        game->player.pX++;

    game->map[game->player.pY][game->player.pX] = game->player.renderValue;


}




void checkInteract(Map* game)
{
    if(GetAsyncKeyState(VK_R)){}

}






#endif