#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.c"
#include "main.h"
#include <windows.h>
#include <conio.h>




void showMap(Room *game, MapData screenData)
{
    HIDE_CURSOR();
    MOVE_HOME();


    fflush(stdout);


    int wall = game->objects.renderWall;

    int up;
    int down;
    int right;
    int left;

        for (int i = 0; i < screenData.rows; i++) 
        {
            for (int j = 0; j < screenData.collums; j++)
            
            
                if(screenData.map[i][j].value == game->player.renderValue)
                    printf("%c%c%c",218,234,191);
                else if (screenData.map[i][j].value == wall)
                {
                    up = (i==0) ? 0 : screenData.map[i-1][j].value;
                    down = (i==screenData.rows-1) ? 0 : screenData.map[i+1][j].value;
                    left = (j==0) ? 0 : screenData.map[i][j-1].value;
                    right = (j==screenData.collums-1) ? 0 : screenData.map[i][j+1].value;

                    if(up == wall && right == wall && down == wall && left == wall)
                        printf("%c%c%c",205,206,205);
                    else if(up == wall && right == wall && down == wall && left != wall)
                        printf(" %c%c",204,205);
                    else if(up == wall && right == wall && down != wall && left != wall)
                        printf(" %c%c",200,205);
                    else if(right == wall && down == wall && left == wall && up != wall)
                        printf("%c%c%c",205,203,205);
                    else if(right == wall && down == wall && left != wall && up != wall)
                        printf(" %c%c",201,205);
                    else if(down == wall && left == wall && up == wall && right != wall)
                        printf("%c%c ",205,185);
                    else if(down == wall && left == wall && up != wall && right != wall)
                        printf("%c%c ",205,187);
                    else if(left == wall && up == wall && right == wall && down != wall)
                        printf("%c%c%c",205,202,205);
                    else if(left == wall && up == wall && right != wall && down != wall)
                        printf("%c%c ",205,188);
                    else if((left || right) && up != wall && down != wall)
                        if(left == wall && right != wall)
                            printf("%c%c ",205,205);
                        else if(left != wall && right == wall)
                            printf(" %c%c",205,205);
                        else
                            printf("%c%c%c",205,205,205);
                    else //if((up || down) && right != wall && left != wall)
                        printf(" %c ",186);
                    
                }
                else if (screenData.map[i][j].value == game->objects.renderStep)
                    printf("%c%c%c",176,176,176);
                else if (screenData.map[i][j].value == game->objects.renderPokeball)
                    printf("{o}");
                else if(!screenData.map[i][j].value)
                    printf("   ");


                else if(screenData.map[i][j].value == game->objects.renderHole)
                    printf("%c%c%c",177,177,177);
                    // printf("%c%c%c",217,217,217);
                else if(screenData.map[i][j].value == game->objects.renderEnemy)
                    printf("<_>");
                
                else if(screenData.map[i][j].value == MESSAGE)
                {   
                    int size = strlen((char*)screenData.map[i][j].entity);
                    // printf("%d",size%3);
                    printf("%s",(char*)screenData.map[i][j].entity);
                    for(int k=0; k < (3 - (size%3)); k++)
                        printf(" ");
                    size = size/3 + ((size%3)/(size%3))-1;

                    j += size; 
                }
            






                // if(screenData.map[i][j].value)
                //     printf("%d  ",screenData.map[i][j].value);
                // else
                //     printf("   ");

            printf("\n");
        }

    fflush(stdout);

}

#endif