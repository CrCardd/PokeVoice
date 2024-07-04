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




void buildHole(Map** map, int coordUpY, int coordUpX)
{
    const int lenght = 3;
    
    for(int i=0; i<lenght; i++)
    {
        map[coordUpY+i][coordUpX].value = HOLE;
        map[coordUpY+i][coordUpX+ (lenght-2)].value = HOLE;
        map[coordUpY+i][coordUpX+ (lenght-1)].value = HOLE;

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
    buildLine(1,screen,0,11,33);
    buildLine(2,screen,0,1,10);
    buildLine(2,screen,30,1,11);


    buildLine(1,screen,0,35,79);
    buildLine(1,screen,0,62,79);
    buildLine(2,screen,0,36,26);
    buildLine(2,screen,78,36,26);


    // buildLine(2,screen,2,37,24);
    // buildLine(2,screen,31,37,24); 
    // buildLine(1,screen,2,37,29);
    // buildLine(1,screen,2,60,29);



    //MOLDE
        buildSquare(screen, 37,33,60,76,1);
        buildLine(1,screen, 34,49,42);
        buildLine(1,screen, 34,48,42);
        buildLine(2,screen, 55,37,23);


    //QUADRANTES
        //1/4
            // buildSquare(screen,37,33,48,54,1);
    //WHAT
            buildLine(2,screen, 2, 39, 8);
            buildLine(1,screen, 2, 46, 2);
            buildLine(2,screen, 4, 43, 4);
            buildLine(1,screen, 4, 46, 2);
            buildLine(2,screen, 6, 39, 8);

            buildLine(2,screen, 8, 39, 8);
            buildLine(1,screen, 8, 42, 2);
            buildLine(2,screen, 10, 39, 8);

            buildLine(2,screen, 12, 39, 8);
            buildLine(1,screen, 12, 39, 2);
            buildLine(2,screen, 14, 39, 8);
            buildLine(1,screen, 12, 42, 2);
            
            buildLine(1,screen, 16, 39, 3);
            buildLine(2,screen, 17, 39, 8);

    //WILL
            buildLine(2,screen, 20, 39, 8);
            buildLine(1,screen, 20, 46, 2);
            buildLine(2,screen, 22, 43, 4);
            buildLine(1,screen, 22, 46, 2);
            buildLine(2,screen, 24, 39, 8);
            
            buildLine(2,screen, 26, 40, 7);

            buildLine(2,screen, 28, 39, 8);
            buildLine(1,screen, 28, 46, 2);
            
            buildLine(2,screen, 31, 39, 8);
            buildLine(1,screen, 31, 46, 2);
            
    //DO
            buildLine(2,screen, 20, 52, 7);
            buildLine(1,screen, 20, 51, 2);
            buildLine(2,screen, 22, 51, 1);
            buildLine(1,screen, 22, 52, 1);
            buildLine(2,screen, 23, 52, 7);
            buildLine(1,screen, 22, 58, 1);
            buildLine(2,screen, 22, 59, 1);
            buildLine(1,screen, 20, 59, 2);

            buildLine(2,screen, 27, 51, 8);
            buildLine(2,screen, 25, 51, 8);
            buildLine(1,screen, 25, 59, 3);
            buildLine(1,screen, 25, 51, 2);

            
            buildLine(2,screen, 29, 50, 3);
            buildLine(1,screen, 29, 50, 2);
            buildLine(2,screen, 31, 50, 5);
            buildLine(1,screen, 29, 54, 2);
            buildLine(2,screen, 29, 54, 4);
            buildLine(2,screen, 29, 60, 1);//Cristian arruma

            


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
            buildLine(2,screen,38,40,7);
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
            buildLine(2,screen,59,52,7);

            buildLine(1,screen,59,51,4);
            buildLine(1,screen,61,54,2);
            buildLine(2,screen,62,52,2);
            
            buildLine(2,screen,61,54,5);
            buildLine(1,screen,60,58,1);
            // buildLine(2,screen,61,56,1);
        //U
            buildLine(2,screen,64,51,8);
            buildLine(2,screen,67,51,8);
            buildLine(1,screen,65,58,2);
        //N
            buildLine(2,screen,69,51,8);
            buildLine(2,screen,73,51,8);

            buildLine(1,screen,70,51,2);
            
            buildLine(2,screen,71,52,7);

            buildLine(1,screen,72,58,2);

    //BAG

            buildLine(2,screen, 59, 40, 6);
            buildLine(2,screen, 62, 40, 6);
            buildLine(1,screen, 59, 46, 3);
            buildLine(1,screen, 59, 39, 3);
            buildLine(1,screen, 61, 43, 1);

            buildLine(2,screen, 64, 39, 7);
            buildLine(1,screen, 64, 39, 3);
            buildLine(2,screen, 67, 39, 7);
            buildLine(1,screen, 64, 42, 3);

            buildLine(2,screen, 69, 39, 7);
            buildLine(1,screen, 69, 39, 3);
            buildLine(1,screen, 69, 46, 4);
            buildLine(2,screen, 72, 44, 2);
            buildLine(1,screen, 71, 43, 2);

    //BALL

            buildLine(2,screen, 36 , 52, 6);
            buildLine(2,screen, 39, 52, 6);
            buildLine(1,screen, 36, 58, 3);
            buildLine(1,screen, 36, 51, 3);
            buildLine(1,screen, 38, 55, 1);

            buildLine(2,screen, 41, 51, 7);
            buildLine(1,screen, 41, 51, 3);
            buildLine(2,screen, 44, 51, 7);
            buildLine(1,screen, 41, 54, 3);

            buildLine(2,screen, 46, 51, 7);
            buildLine(1,screen, 46, 58, 3);

            buildLine(2,screen, 50, 51, 7);
            buildLine(1,screen, 50, 58, 3);


}


#endif 