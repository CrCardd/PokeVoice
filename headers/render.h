#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <stdlib.h>
#include "terminal.c"
#include "main.h"
#include <windows.h>

void showMap(Room *game)
{

    ERASE_ALL();
    MOVE_HOME();
    HIDE_CURSOR();

        for (int i = 0; i < game->rows; i++) 
        {
            for (int j = 0; j < game->collums; j++) 
            
                // if(game->map[i][j] == game->player.renderValue)
                //     printf("X  ");
                // else if (game->map[i][j] == game->objects.renderWall)
                //     printf("// ");
                // else if (game->map[i][j] == game->objects.renderPokeball)
                //     printf("O  ");
                // else if(!game->map[i][j])
                //     printf("   ");
                // else
                //     printf("F  ");
                if(game->map[i][j])
                    printf("%d  ",game->map[i][j]);
                else
                    printf("   ");
            printf("\n");
        }




    fflush(stdout);
    
    // Sleep(75);
}

#endif