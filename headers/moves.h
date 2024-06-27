#ifndef MOVES_H 
#define MOVES_H 
 
#include <windows.h>
#include "keycodes.h"
#include "main.h"
#include <math.h>

#define M_PI 3.14159265358979323846

void checkWalk(Map* game)
{
    //WALK
    if(GetAsyncKeyState(VK_W) && game->player.pY)
        game->player.pY--;
    if(GetAsyncKeyState(VK_S) && game->player.pY+1<game->rows)
        game->player.pY++;
    if(GetAsyncKeyState(VK_A) && game->player.pX)
        game->player.pX--;
    if(GetAsyncKeyState(VK_D) && game->player.pX+1<game->collums)
        game->player.pX++;
}

void checkInteract(Map* game)
{
    if(GetAsyncKeyState(VK_R))
    {
        for(int i=0; i<4; i++)
        {
            int lin = game->player.pY + sin(i*0.5* M_PI);
            int col = game->player.pX + cos(i*0.5* M_PI);
            if(game->map[lin][col])
            {
                //sampaio trampa
                game->map[lin][col] = 0;
                break;
            }
        }



        // if(game->map[game->player.pY-1][game->player.pX] == 5) //em cima do player
        //     {
        //         game->map[game->player.pY-1][game->player.pX] = 0;
        //         //sampaio trampa
        //     }

        // if(game->map[game->player.pY+1][game->player.pX] == 5) //embaixo do player
        //     {
        //         game->map[game->player.pY+1][game->player.pX] = 0;
        //         //sampaio trampa
        //     }

        // if(game->map[game->player.pY][game->player.pX-1] == 5) //lado direito do player 
        //     {
        //         game->map[game->player.pY][game->player.pX-1] = 0;
        //         //sampaio trampa
        //     }

        // if(game->map[game->player.pY][game->player.pX+1] == 5) //lado esquerdo do player
        //     {
        //         game->map[game->player.pY][game->player.pX+1] = 0;
        //         //sampaio trampa
            // }
    }
}






#endif