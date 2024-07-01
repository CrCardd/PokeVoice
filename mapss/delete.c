#include <stdio.h>
#include "buildMap.h"
#include "create.h"



    void printWall(int x, int y, Map *map) 
{
    int up = 0, down = 0, left = 0, right = 0;

    if (x != 19)
    {
        if (map->map[y][x+1] == 1) {right = 1;}
    }
    if (x != 0)
    {
        if (map->map[y][x-1] == 1) {left = 1;}
    }
    if (y != 19)
    {
        if (map->map[y+1][x] == 1) {down = 1;}
    }
    if (y != 0)
    {
        if (map->map[y-1][x] == 1) {up = 1;}
    }

    if (up && down && right) {printf("%c%c", 204, 205);}

    else if (left && up && right) {printf("%c%c", 202, 205);}

    else if (left && down && right) {printf("%c%c", 203, 205);}

    else if (up && left && down) {printf("%c ", 185);}

    else if (up && right && down) {printf("%c%c", 204, 205);}

    else if (left && up) {printf("%c ", 188);}

    else if (left && down) {printf("%c ", 187);}

    else if (up && right) {printf("%c%c", 200, 205);}

    else if (right && down) {printf("%c%c", 201, 205);}

    else if (up || down) {printf("%c ", 186);}

    else if (left || right)
    {
        if (left && !right) {printf("%c ", 205);}

        else {printf("%c%c", 205, 205);}
    }
    else {printf("o ");}
}

int main()
{
    system("color 50");
    Player player = playerInnit(0,0);
    Map map = gameInnit(63,79, player);

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
    // printf("%c\n\n", 185);
    // printf("%c\n\n", 186);
    // printf("%c\n\n", 187);
    // printf("%c\n\n", 188);
    // printf("%c\n\n", 200);
    // printf("%c\n\n", 201);
    // printf("%c\n\n", 202);
    // printf("%c\n\n", 203);
    // printf("%c\n\n", 204);
    // printf("%c\n\n", 205);
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGHT; j++)
        {
            printWall(i,j,&map);
        }
        
    }
    

    return 0;
}
