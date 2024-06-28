#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <stdlib.h>
#include "terminal.c"
#include "main.h"
#include <windows.h>

void showMap(Map *game)
{
    system("cls");
    HIDE_CURSOR();

        for (int i = 0; i < game->rows; i++) 
        {
            for (int j = 0; j < game->collums; j++) 
            
                if(game->map[i][j] == game->player.renderValue)
                    printf("X  ");
                else if (game->map[i][j] == game->renderWall)
                    printf("// ");
                else if (game->map[i][j] == game->renderPokeball)
                    printf("O  ");
                else if(!game->map[i][j])
                    printf("   ");
                else
                    printf("F  ");
                
                // printf("%d  ",game->map[i][j]);
            printf("\n");
        }

    



    // char *formattedString = malloc(3 * game->rows * game->collums); // Adjust size as needed
    // // Use sprintf to construct the formatted string
    // int offset = 0; // Offset to keep track of the position in the string
    //     for (int i = 0; i < game->rows; i++) 
    //         for (int j = 0; j < game->collums; j++) 
    //         {
    //             if(game->map[i][j] == 2)
    //                 offset += sprintf(formattedString + offset, "X  ");
    //             else if (game->map[i][j] == 1)
    //                 offset += sprintf(formattedString + offset, "//  ");
    //             else if(!game->map[i][j])
    //                 offset += sprintf(formattedString + offset, "   ");
    //             else
    //                 offset += sprintf(formattedString + offset, "F  ");

    //         }
    // printf("%s", formattedString);    



    fflush(stdout);
    MOVE_HOME();
    
    Sleep(75);
}

#endif