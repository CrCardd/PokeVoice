/* Compile:
gcc main.c -o Poke.exe -l gdi32 -l msimg32
*/

#include "headers/headers.h"

#define LIM_X 79
#define LIM_Y 63


HANDLE TerminalThread;
HANDLE FunctionsThread;

DWORD WINAPI showMapThread(LPVOID lpParam)
{
    Map *game = (Map*)lpParam;
    while (1)
    {
        showMap(game);
        // Sleep(100); // ajuste o tempo conforme necessário
    }
    return 0;
}

DWORD WINAPI checkWalkThread(LPVOID lpParam)
{
    Map *game = (Map*)lpParam;
    while (1)
    {
        checkWalk(game);
        // Sleep(100); // ajuste o tempo conforme necessário
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    configureTerminal();
    ERASE_ALL();

    Player player = playerInnit(2,2,2);
    Map game = gameInnit(LIM_Y, LIM_X, player,1);
    // game.map[game.player.pY][game.player.pX] = game.player.renderValue;

    buildSquare(&game, 10,10,50,50);
    
    printf("LOADING...\n");


    TerminalThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)showMapThread, &game, 0, NULL);
    FunctionsThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)checkWalkThread, &game, 0, NULL);

    WaitForSingleObject(TerminalThread, INFINITE);
    WaitForSingleObject(FunctionsThread, INFINITE);

    return 0;

}
