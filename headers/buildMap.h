#ifndef BUILDMAP
#define BUILDMAP

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "main.h"


void buildLine(int mode,Room *map,int coordX, int coordY, int size)
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


void buildSquare(Room* map, int coordY, int coordX, int coordY_, int coordX_)
{
    int lenght = coordX_ - coordX;
    int height = coordY_ - coordY;
    int biggest = (height>lenght)?height:lenght;
    for(float i=0; i<=biggest; i++)
    {
        map->map[coordY + (int)((i/biggest)*height)][coordX] = 1;
        map->map[coordY_ - (int)((i/biggest)*height)][coordX_] = 1;
        map->map[coordY][coordX + (int)((i/biggest)*lenght)] = 1;
        map->map[coordY_][coordX_ - (int)((i/biggest)*lenght)] = 1;
    }
}


#endif 