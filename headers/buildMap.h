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





void resetScreen(MapData * mapData)
{
    for(int i=0; i<mapData->rows; i++)
        for(int j=0; j<mapData->collums; j++)
            mapData->map[i][j].value = 0;
}



void fightScreenConstruct(Map **screen)
{


    buildLine(1,screen,0,1,30);
    buildLine(1,screen,0,11,30);
    buildLine(2,screen,0,0,11);
    buildLine(2,screen,41,0,11);


    buildLine(1,screen,0,35,79);
    buildLine(1,screen,0,62,79);
    buildLine(2,screen,0,36,26);
    buildLine(2,screen,78,36,26);


    buildLine(2,screen,2,37,24);
    buildLine(2,screen,31,37,24);
    buildLine(1,screen,2,37,29);
    buildLine(1,screen,2,60,29);



    //MOLDE
        // buildSquare(screen, 37,33,60,76,1);
        // buildLine(1,screen, 34,49,42);
        // buildLine(1,screen, 34,48,42);
        // buildLine(2,screen, 55,37,23);


    //QUADRANTES
        //1/4
            // buildSquare(screen,37,33,48,54,1);
        //2/4
            // buildSquare(screen,37,55,48,76,1);
        //3/4
            // buildSquare(screen,49,33,60,54,1);
        //4/4
            // buildSquare(screen,49,55,60,76,1);

    //FIGHT
        //F
            buildLine(1,screen,35,39,2);
            buildLine(2,screen,35,40,7);
            buildLine(1,screen,36,43,1);
        //I
            buildLine(2,screen,38,39,8);
        //G
            buildLine(1,screen,40,39,4);
            buildLine(1,screen,41,46,4);
            buildLine(1,screen,42,43,2);
            buildLine(2,screen,40,40,7);
            buildLine(2,screen,44,43,4);
        //H
            buildLine(2,screen,46,39,8);
            buildLine(2,screen,48,39,8);
            buildLine(2,screen,47,43,1);
        //T
            buildLine(1,screen,50,39,3);
            buildLine(2,screen,51,40,7);

    //RUN
        //R
            buildLine(1,screen,59,51,4);
            buildLine(2,screen,62,52,3);
            buildLine(1,screen,60,54,2);
            buildLine(2,screen,59,52,7);
            buildLine(2,screen,62,57,2);
            buildLine(2,screen,60,55,1);
            buildLine(2,screen,61,56,1);
        //U
            buildLine(2,screen,64,51,8);
            buildLine(2,screen,67,51,8);
            buildLine(1,screen,65,58,2);
        //N
            buildLine(2,screen,69,51,8);
            buildLine(2,screen,73,51,8);
            buildLine(2,screen,71,53,4);
            buildLine(2,screen,70,51,1);
            buildLine(2,screen,72,57,1);


}


#endif 