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
    
    Player player = playerInnit(PLAYER,5,5);
    Objects objects = objectsInnit(POKEBALL, ENEMY, WALL,HOLE);
    Room map = gameInnit(ROWS,COLLUMS, player, objects);
    push(&map.stackEvents, &map.mapScreen);

    mapConstruct(map.mapScreen.map);
    fightScreenConstruct(map.fightScreen.map);


    // map.mapScreen.map[40][40].entity = "mensagem para a tela HAHA";
    // map.mapScreen.map[40][40].value = MESSAGE;   

    showMap(&map,map.fightScreen);


    /*  
    Mutex = CreateMutex(NULL, FALSE, NULL);

    checkKeyboardThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)checkKeyboard, &map, 0, NULL);
    showScreenThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)showScreen, &map, 0, NULL);

    WaitForSingleObject(showScreenThread,showScreen);
    WaitForSingleObject(checkKeyboardThread,checkKeyboard);

    CloseHandle(Mutex);
    */
    return 0;
}   