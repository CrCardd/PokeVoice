#ifndef BUILDMAP
#define BUILDMAP

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "create.h"

#define HEIGHT 63
#define LENGHT 79
#define CHARACTER Ω;


void showMap(Map *map)
{
    for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGHT; j++)
                if (map->map[i][j] == 0)
                    printf("   ");
                else if (map->map[i][j] == 1)
                    printf("// ");

                else if (map->map[i][j] == 3)
                    printf("!! ");   
                // else if (map->map[i][j] == 3)
                //     printf("!! ");   
                

            printf("\n");  
        }
}


void buildLine(int mode,Map *map,int coordX, int coordY, int size)
{
    if(mode == 1)
    {
        for (int i = coordX; i < coordX + size; i++)
            map->map[coordY][i] = 1;
        
    }else if (mode == 2)
    {
        for (int i = coordY; i < coordY + size; i++)
            map->map[i][coordX] = 1;
    }else
    {
        map->map[coordX][coordY] = 5;
    }    
}


void buildHole(Map* map, int coordUpY, int coordUpX)
{
    const int lenght = 3;
    
    for(int i=0; i<lenght; i++)
    {
        map->map[coordUpY+i][coordUpX] = 3;
        map->map[coordUpY+i][coordUpX+ (lenght-2)] = 3;
        map->map[coordUpY+i][coordUpX+ (lenght-1)] = 3;

    }

}
#endif 