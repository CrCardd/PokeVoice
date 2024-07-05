/*
gcc maps/map1.c -o Poke.exe -l gdi32 -l msimg32
*/

#include "../headers/headers.h"

#include "map1.h"


HANDLE showScreenThread;
HANDLE checkKeyboardThread;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    configureTerminal();
    
    Player player = playerInnit(PLAYER,60,70);
    player.team = myTeamConstructor();
    Objects objects = objectsInnit(POKEBALL, ENEMY, WALL,HOLE,STEP);
    Room map = gameInnit(ROWS,COLLUMS, player, objects);
    push(&map.stackEvents, &map.mapScreen);
    spawnEnemy(map.mapScreen.map, ENEMY, 35,63);

    mapConstruct(map.mapScreen.map);
    secondMapConstruct(map.secondMapScreen.map);



    // /*  
    Mutex = CreateMutex(NULL, FALSE, NULL);

    checkKeyboardThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)checkKeyboard, &map, 0, NULL);
    showScreenThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)showScreen, &map, 0, NULL);

    WaitForSingleObject(showScreenThread,showScreen);
    WaitForSingleObject(checkKeyboardThread,checkKeyboard);
    CloseHandle(Mutex);
    // */
    return 0;
}