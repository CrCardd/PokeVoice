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
    
    Player player = playerInnit(PLAYER,60,70);
    Objects objects = objectsInnit(POKEBALL, ENEMY, WALL,HOLE,STEP);
    Room map = gameInnit(ROWS,COLLUMS, player, objects);
    push(&map.stackEvents, &map.mapScreen);


    mapConstruct(map.mapScreen.map);
    secondMapConstruct(map.secondMapScreen.map);
    fightScreenConstruct(map.fightScreen.map);


    map.mapScreen.map[35][63].value = ENEMY;




    // map.mapScreen.map[40][40].entity = "sampaio o broxissimo";
    // map.mapScreen.map[40][40].value = MESSAGE;




    // push(&map.stackEvents,&map.fightScreen);
    // map.screenModes.Fight = 1;
    // map.screenModes.Map = 0;

    // map.fightScreen.selectOptions.actions = playerInnit(0,0,0);
    



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