#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <stdlib.h>
#include "terminal.c"
#include "main.h"
#include <windows.h>

void showMap(Room *game, Map** screen)
{

    // ERASE_ALL();
    MOVE_HOME();
    HIDE_CURSOR();
    system("cls");
    int wall = game->objects.renderWall;

    int up;
    int down;
    int right;
    int left;

        for (int i = 0; i < game->rows; i++) 
        {
            for (int j = 0; j < game->collums; j++) 
            
                if(screen[i][j].value == game->player.renderValue)
                    printf(" %c ",190);
                else if (screen[i][j].value == wall)
                {
                    up = (i==0) ? 0 : screen[i-1][j].value;
                    down = (i==game->rows-1) ? 0 : screen[i+1][j].value;
                    left = (j==0) ? 0 : screen[i][j-1].value;
                    right = (j==game->collums-1) ? 0 : screen[i][j+1].value;

                    if(up == wall && right == wall && down == wall && left == wall)
                        printf("%c%c%c",206,205,205);
                    else if(up == wall && right == wall && down == wall && left != wall)
                        printf("%c%c%c",204,205,205);
                    else if(up == wall && right == wall && down != wall && left != wall)
                        printf("%c%c%c",200,205,205);
                    else if(right == wall && down == wall && left == wall && up != wall)
                        printf("%c%c%c",203,205,205);
                    else if(right == wall && down == wall && left != wall && up != wall)
                        printf("%c%c%c",201,205,205);
                    else if(down == wall && left == wall && up == wall && right != wall)
                        printf("%c  ",185);
                    else if(down == wall && left == wall && up != wall && right != wall)
                        printf("%c  ",187);
                    else if(left == wall && up == wall && right == wall && down != wall)
                        printf("%c%c%c",202,205,205);
                    else if(left == wall && up == wall && right != wall && down != wall)
                        printf("%c  ",188);
                    else if((up || down) && right != wall && left != wall)
                        printf("%c  ",186);
                    else if((left || right) && up != wall && down != wall)
                        printf("%c%c%c",205,205,205);
                }
                
                else if (screen[i][j].value == game->objects.renderPokeball)
                    printf(" O ");
                else if(!screen[i][j].value)
                    printf("   ");


                else
                    printf("F  ");






                // if(game->map[i][j].value)
                //     printf("%d  ",game->map[i][j].value);
                // else
                //     printf("   ");

            printf("\n");
        }

    fflush(stdout);
}

#endif