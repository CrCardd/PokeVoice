#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include "terminal.c"
#include "main.h"

void showMap(Map *game)
{   
    ERASE_ALL();
    HIDE_CURSOR();

    for(int i=0; i<game->rows; i++){
        for(int j=0; j<game->collums; j++)
        if((i == game->player.pX && j == game->player.pX))
            printf("Ω  ");
        else if(game->map[i][j])
            printf("%d  ",game->map[i][j]);
        else 
            printf("   ");
        printf("\n");
    }


    fflush(stdout);
    MOVE_HOME();
}

#endif