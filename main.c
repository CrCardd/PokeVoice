/* Compile:
gcc main.c -o Poke.exe -l gdi32 -l msimg32
*/

#include "headers/headers.h"

#define LIM_X 79
#define LIM_Y 63




int main()
{   
    // configureTerminal();
    // ERASE_ALL();
    Player player = playerInnit(10,10);
    Map game = gameInnit(LIM_Y, LIM_X, player);
    
    game.map[30][30] = 5;
    while (1) 
    {
        checkWalk(&game);
        // printf("y: %d x: %d\n",game.player.pY, game.player.pX);
        showMap(&game);

    }
}   