/* Compile:
gcc main.c -o Poke.exe -l gdi32 -l msimg32
*/

#include "headers/headers.h"

#define LIM_X 79
#define LIM_Y 63




int main()
{   
    configureTerminal();
    ERASE_ALL();

    Player player = playerInnit(2,15,15);
    Map game = gameInnit(LIM_Y, LIM_X, player,1);

    buildSquare(&game, 0,0,29,19);
    


    printf("LOADING...\n");

    while (1) 
    {

        // printf("y %d   x %d\n",game.player.pY,game.player.pX);
        checkWalk(&game);
        
        showMap(&game);

        Sleep(75);

    }
}   