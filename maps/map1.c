/*
gcc maps/map1.c -o maps/map1.exe -l gdi32 -l msimg32
*/

#include "../headers/headers.h"

#include "map1.h"


HANDLE showScreenThread;
HANDLE checkKeyboardThread;

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    configureTerminal();
    
    Player player = playerInnit(PLAYER,2,2);
    Objects objects = objectsInnit(POKEBALL, ENEMY, WALL);
    Room map = gameInnit(ROWS,COLLUMS, player, objects);



    mapConstruct(map.mapScreen.map);
    fightScreenConstruct(map.fightScreen.map);


    map.mapScreen.map[8][8].value = ENEMY;

    MapData event = peek(&map.stackEvents);

    // int a;
    // showMap(&map,event);
    // push(&map.stackEvents,&map.fightScreen);
    // scanf(" %d",&a);
    // event = peek(&map.stackEvents);
    // showMap(&map, *event);

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

