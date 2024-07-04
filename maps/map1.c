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
    
    // Player player = playerInnit(PLAYER,60,70);
    Player player = playerInnit(PLAYER,35,64);

    player.team = myTeamConstructor();
    Objects objects = objectsInnit(POKEBALL, ENEMY, WALL,HOLE,STEP);
    Room map = gameInnit(ROWS,COLLUMS, player, objects);
    push(&map.stackEvents, &map.mapScreen);


    mapConstruct(map.mapScreen.map);
    secondMapConstruct(map.secondMapScreen.map);



    spawnEnemy(map.mapScreen.map, ENEMY, 35,63);


    // printf("%s\n",map.player.team.pokes[0].atk[0].name);
    // printf("%s\n",map.player.team.pokes[0].atk[1].name);
    // printf("%s\n",map.player.team.pokes[0].atk[2].name);
    // printf("%s\n",map.player.team.pokes[0].atk[3].name);



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