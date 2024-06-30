#ifndef MAP1_H
#define MAP1_H

#include "../headers/main.h"
#include "../headers/buildMap.h"

#include <stdio.h>


void mapConstruct(Map ** screen)
{
    
    buildLine(1,screen, 0, 0, 79);
    buildLine(1,screen, 0, 62, 79);
    buildLine(2,screen, 0, 0, 62);
    buildLine(2,screen, 77, 0, 62);


    buildLine(2,screen, 29, 0, 24);
    buildLine(2, screen, 58, 0, 24);

    buildLine(1, screen, 0, 24, 78);

    buildLine(2, screen, 20, 24, 33);
    buildLine(2, screen, 35, 24, 38);
    buildLine(2, screen, 50, 24, 26);

    buildLine(1, screen, 20, 54, 15);
    buildLine(1, screen, 50, 45, 28);
}




#endif //MAP1_H