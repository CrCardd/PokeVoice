#ifndef PRESETTHREAD_H
#define PRESETTHREAD_H

#include "render.h"
#include "stack.h"
#include "main.h"
#include "moves.h"

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

        
        checkMove(map,event);
        checkInteract(map);
        checkEnemy(map);

        ReleaseMutex(Mutex);
    }
}

#endif //PRESETTHREAD_H