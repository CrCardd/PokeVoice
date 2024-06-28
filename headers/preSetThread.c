#ifndef PRESETTHREAD_H
#define PRESETTHREAD_H

#include "render.h"
#include "main.h"
#include "moves.h"

HANDLE Mutex;

DWORD showScreen(void *arg)
{
    Room * map = (Room*) arg;
    while(1)
    {
        WaitForSingleObject(Mutex, INFINITE);

        if(map->screenModes.Map)
            showMap(map);

        ReleaseMutex(Mutex);
    }   
}


DWORD checkKeyboard(void *arg)
{
    Room * map = (Room*) arg;
    
    while(1)
    {
        WaitForSingleObject(Mutex, INFINITE);

        checkWalk(map);
        checkInteract(map);
        checkInteract(map);

        ReleaseMutex(Mutex);
    }
}

#endif //PRESETTHREAD_H