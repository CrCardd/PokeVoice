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

            checkHole(map);

            checkEnemy(map);
        }
        if(map->screenModes.Fight)
        {
            selectOption(map);
        }

        ReleaseMutex(Mutex);
    }
}

#endif //PRESETTHREAD_H