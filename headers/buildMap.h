#ifndef BUILDMAP
#define BUILDMAP

#include "main.h"


void buildLine(int mode, Map ** screen,int coordX, int coordY, int size)
{
     if(mode == 1)
     {
            for (int i = coordX; i < (coordX + size); i++)
               screen[coordY][i].value = 1;
     }  // HORIZONTAL
        
    else if(mode == 2)
    {
            for (int i = coordY; i < (coordY + size); i++)
                screen[i][coordX].value = 1;
    } // VERTICAL

    else
    {
            screen[coordX][coordY].value = 5;
    }
    
}


void buildSquare(Map ** map, int coordY, int coordX, int coordY_, int coordX_, int value)
{
    int lenght = coordX_ - coordX;
    int height = coordY_ - coordY;
    int biggest = (height>lenght)?height:lenght;
    for(float i=0; i<=biggest; i++)
    {
        map[coordY + (int)((i/biggest)*height)][coordX].value = value;
        map[coordY_ - (int)((i/biggest)*height)][coordX_].value = value;
        map[coordY][coordX + (int)((i/biggest)*lenght)].value = value;
        map[coordY_][coordX_ - (int)((i/biggest)*lenght)].value = value;
    }
}



#endif 