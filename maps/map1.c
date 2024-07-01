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



    mapConstruct(map.mapScreen.map);
    fightScreenConstruct(map.fightScreen.map);




    map.mapScreen.map[4][30].value = POKEBALL;
    map.mapScreen.map[6][8].value = ENEMY;
    map.mapScreen.map[20][8].value = HOLE;
    map.mapScreen.map[20][8].tp_X = 50;
    map.mapScreen.map[20][8].tp_Y = 10;

    map.mapScreen.map[10][50].value = HOLE;
    map.mapScreen.map[10][50].tp_X = 8;
    map.mapScreen.map[10][50].tp_Y = 20;



    // map.mapScreen.map[40][40].entity = "mensagem para a tela HAHA";
    // map.mapScreen.map[40][40].value = MESSAGE;




    // push(&map.stackEvents,map.fightScreen);
    // map.screenModes.Fight = 1;
    // map.screenModes.Map = 0;

    // map.playerActions = playerInnit(0,0,0);

    

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

