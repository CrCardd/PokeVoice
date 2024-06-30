#ifndef PRESETTHREAD_H
#define PRESETTHREAD_H

#include "render.h"
#include "stack.h"
#include "main.h"
#include "moves.h"

#include <stdio.h>

HANDLE Mutex;

DWORD showScreen(void *arg)
{
    Room * map = (Room*) arg;
    while(1)
    {
        MapData event = peek(&map->stackEvents);
        WaitForSingleObject(Mutex, INFINITE);

        if(map->screenModes.Map)    
            system("color 50");
        // if(map->screenModes.Fight)
            //COLOR

        showMap(map,event);
        
        
        ReleaseMutex(Mutex);
    }   
}


DWORD checkKeyboard(void *arg)
{
    Room * map = (Room*) arg;
    
    while(1)
    {
        MapData event = peek(&map->stackEvents);
        
        WaitForSingleObject(Mutex, INFINITE);

        if(map->screenModes.Map)
        {
            checkMove(map);
            checkInteract(map);
            checkEnemy(map);
        }
        if(map->screenModes.Fight)
        {
            chooseOption(map);
            // printf("y %d      x%d\n",map->playerActions.pY,map->playerActions.pX);
            

        }

        ReleaseMutex(Mutex);
    }
}

#endif //PRESETTHREAD_H