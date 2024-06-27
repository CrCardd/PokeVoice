#ifndef BUILDMAP_H
#define BUILDMAP_H

#define LENGHT 79
#define HEIGHT 63

#include "main.h"

void buildSquare(Map* map, int coordY, int coordX, int coordY_, int coordX_)
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