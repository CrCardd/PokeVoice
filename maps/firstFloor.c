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
    buildLine(2,&map, 33, 0, 24);
    buildLine(2, &map, 56, 0, 24);

    buildLine(1, &map, 0, 24, 78);

    buildLine(2, &map, 20, 24, 33);
    buildLine(2, &map, 35, 24, 38);
    buildLine(2, &map, 50, 24, 26);

    buildLine(1, &map, 20, 54, 15);
    buildLine(1, &map, 50, 45, 28);

    //Buracos
    buildHole(&map, 7, 12);
    buildHole(&map, 3, 30);
    buildHole(&map, 21, 1);
    buildHole(&map, 21, 27);

    buildHole(&map, 3, 34);
    buildHole(&map, 21, 37);
    buildHole(&map, 21, 50);

    buildHole(&map, 7, 59);
    buildHole(&map, 21, 70);

    buildHole(&map, 30, 1);
    buildHole(&map, 30, 17);
    buildHole(&map, 47, 9);
    buildHole(&map, 47, 15);
    buildHole(&map, 50, 12);
    buildHole(&map, 55, 1);

    buildHole(&map, 28, 23);
    buildHole(&map, 47, 23);
    
    buildHole(&map, 28, 36);
    buildHole(&map, 57, 42);

    buildHole(&map, 40, 56);


    showMap(&map);
}

