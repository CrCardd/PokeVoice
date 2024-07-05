#ifndef MAP1_H
#define MAP1_H

#include "../headers/main.h"
#include "../headers/buildMap.h"

#include <stdio.h>


void mapConstruct(Map ** screen)
{

    
    
    //Limites do mapa
    buildLine(1,screen, 0, 0, 79);
    buildLine(1,screen, 0, 62, 79);
    buildLine(2,screen, 0, 0, 62);
    buildLine(2,screen, 78, 0, 62);

    //Paredes
    buildLine(2,screen, 33, 0, 24);
    buildLine(2, screen, 56, 0, 24);

    buildLine(1, screen, 0, 24, 78);

    buildLine(2, screen, 20, 24, 33);
    buildLine(2, screen, 35, 24, 38);
    buildLine(2, screen, 50, 24, 26);

    buildFullSquare(screen,54,21,55,35,STEP);

    buildFullSquare(screen,45,51,46,78, STEP);

    //Buracos
    buildHole(screen, 7, 12);
    buildHole(screen, 21, 1);
    buildHole(screen, 21, 27);

    buildHole(screen, 3, 34);
    buildHole(screen, 21, 35);
    buildHole(screen, 21, 50);

    buildHole(screen, 21, 70);

    buildHole(screen, 30, 1);
    buildHole(screen, 47, 9);
    buildHole(screen, 55, 1);

    buildHole(screen, 28, 23);
    buildHole(screen, 47, 23);
    
    buildHole(screen, 28, 36);
    buildHole(screen, 57, 42);

    buildHole(screen, 40, 56);
}


void secondMapConstruct(Map ** screen)
{
    //Limites do mapa
    buildLine(1,screen, 0, 0, 79);
    buildLine(1,screen, 0, 62, 79);
    buildLine(2,screen, 0, 0, 62);
    buildLine(2,screen, 78, 0, 62);

    //Paredes
    buildLine(2,screen, 25, 0, 4);
    buildLine(2, screen, 50, 0, 4);
    buildLine(1, screen, 0, 10, 78);
    buildLine(2, screen, 20, 11, 43);
    buildLine(2, screen, 32, 11, 43);
    buildLine(2, screen, 39, 11, 51);
    buildLine(2, screen, 60, 11, 45);






    
    



    buildFullSquare(screen,35,1,36,20, STEP);
    buildFullSquare(screen,32,21,33,32,STEP);
    buildFullSquare(screen,28,40,29,60,STEP);
    buildFullSquare(screen,48,40,49,60,STEP);
    buildFullSquare(screen,28,61,29,78,STEP);


    //Buracos
    buildHole(screen, 7, 12);
    buildHole(screen, 3, 34);
    buildHole(screen, 7, 59);


    buildHole(screen, 21, 1);
    buildHole(screen, 47, 9);

    buildHole(screen, 30, 1);
    buildHole(screen, 55, 1);

    buildHole(screen, 47, 23);
    
    buildHole(screen, 28, 36);
    buildHole(screen, 40, 56);    
    buildHole(screen, 57, 42);


    buildHole(screen, 40, 40);
}




#endif //MAP1_H