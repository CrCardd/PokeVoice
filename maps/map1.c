#include "../headers/headers.h"

int main()
{
    configureTerminal();
    ERASE_ALL();

    system("color 50");
    Player player = playerInnit(2,2,2);
    Map map = gameInnit(63,79, player, 1);

    buildLine(1,&map, 0, 0, 79);
    buildLine(1,&map, 0, 62, 79);
    buildLine(2,&map, 0, 0, 62);
    buildLine(2,&map, 78, 0, 62);


    buildLine(2,&map, 29, 0, 24);
    buildLine(2, &map, 58, 0, 24);

    buildLine(1, &map, 0, 24, 78);

    buildLine(2, &map, 20, 24, 33);
    buildLine(2, &map, 35, 24, 38);
    buildLine(2, &map, 50, 24, 26);

    buildLine(1, &map, 20, 54, 15);
    buildLine(1, &map, 50, 45, 28);


    while(1)
    {
        checkWalk(&map);
        showMap(&map);

    }
}

