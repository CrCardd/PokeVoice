#ifndef PRESETTHREAD_H
#define PRESETTHREAD_H

#include "render.h"
#include "main.h"
#include "moves.h"

HANDLE Mutex;

DWORD showScreen(void *arg)
{
    Room * map = (Room*) arg;
    // while(1)
    // {
        // WaitForSingleObject(Mutex, INFINITE);

        // if(map->screenModes.Map)    
        //     system("color 50");
        //     showMap(map,map->mapScreen);
        // if(map->screenModes.Fight)
            showMap(map,map->fightScreen);
        
        
        // ReleaseMutex(Mutex);
    // }   
}


DWORD checkKeyboard(void *arg)
{
    Room * map = (Room*) arg;
    
    while(1)
    {
        WaitForSingleObject(Mutex, INFINITE);

        if(map->screenModes.Map)
        {
            checkMove(map,map->mapScreen);
            checkInteract(map);
            checkEnemy(map);
        }

        if(map->screenModes.Fight)
            checkMove(map,map->fightScreen);

        ReleaseMutex(Mutex);
    }
}

#endif //PRESETTHREAD_H