#ifndef BUILDMAP
#define BUILDMAP

#include "main.h"


void buildLine(int mode, Map ** screen,int coordX, int coordY, int size)
{
     if(mode == 1)
     {
            for (int i = coordX; i < coordX + size; i++)
               screen[coordY][i].value = 1;
     }  // HORIZONTAL
        
    else if(mode == 2)
    {
            for (int i = coordY; i < coordY + size; i++)
                screen[i][coordX].value = 1;
    } // VERTICAL

    else
    {
            screen[coordX][coordY].value = 5;
    }
    
}


// void buildSquare(Room* map, int coordY, int coordX, int coordY_, int coordX_)
// {
//     int lenght = coordX_ - coordX;
//     int height = coordY_ - coordY;
//     int biggest = (height>lenght)?height:lenght;
//     for(float i=0; i<=biggest; i++)
//     {
//         map->mapScreen[coordY + (int)((i/biggest)*height)][coordX].value = 1;
//         map->mapScreen[coordY_ - (int)((i/biggest)*height)][coordX_].value = 1;
//         map->mapScreen[coordY][coordX + (int)((i/biggest)*lenght)].value = 1;
//         map->mapScreen[coordY_][coordX_ - (int)((i/biggest)*lenght)].value = 1;
//     }
// }


#endif 