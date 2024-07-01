#include "buildMap.h"
#include "create.h"

int main()
{
    system("color 50");
    Player player = playerInnit(0,0);
    Map map = gameInnit(63,79, player);

    //Limites do mapa
    buildLine(1,&map, 0, 0, 79);
    buildLine(1,&map, 0, 62, 79);
    buildLine(2,&map, 0, 0, 62);
    buildLine(2,&map, 78, 0, 62);

    //Paredes
    buildLine(2,&map, 25, 0, 4);
    buildLine(2, &map, 50, 0, 4);

    buildLine(1, &map, 0, 10, 78);

    buildLine(1, &map, 0, 35, 20);

    buildLine(2, &map, 20, 11, 43);
    buildLine(1, &map, 20, 32, 12);
    buildLine(2, &map, 32, 11, 43);
    
    buildLine(2, &map, 39, 11, 51);
    
    buildLine(1, &map, 40, 28, 20);
    buildLine(1, &map, 40, 48, 20);

    buildLine(2, &map, 60, 11, 45);
    buildLine(1, &map, 61, 28, 17);


    //Buracos
    buildHole(&map, 7, 12);
    buildHole(&map, 21, 1);

    buildHole(&map, 3, 34);

    buildHole(&map, 7, 59);


    buildHole(&map, 30, 1);

    buildHole(&map, 47, 9);

    buildHole(&map, 55, 1);

    buildHole(&map, 47, 23);
    
    buildHole(&map, 28, 36);
    buildHole(&map, 57, 42);

    buildHole(&map, 40, 56);


    showMap(&map);
}

