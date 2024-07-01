#ifndef CREATE_H
#define CREATE_H

#include <stdlib.h>


typedef struct 
{
    int pX;
    int pY;

} Player;


typedef struct 
{
    int** map;
    int rows;
    int collums;
    Player player;
} Map;


Player playerInnit(int y, int x)
{
    Player player;
    player.pX = x;
    player.pY = y;

    return player;
}


Map gameInnit(int rows, int collums, Player player)
{
    Map map;
    map.rows = rows; 
    map.collums = collums; 
    map.player = player;
    map.map = (int**) malloc(rows * sizeof(int**));
    for(int i=0; i<rows; i++)
    {
        map.map[i] = (int*) malloc(collums * sizeof(int)); 
        for(int j=0; j<collums; j++)
            map.map[i][j] = 0;
    } 
        

    return map;
}
#endif
