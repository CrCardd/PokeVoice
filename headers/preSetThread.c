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
        
        MapData * event = peek(&map->stackEvents);
        WaitForSingleObject(Mutex, INFINITE);

        

        // if(!map->screenModes.Fight)    
        //     BACKGROUND_COLOR(162,171,200);
        

        if(event->screenUpdated)
        {
            showMap(map,*event);
        }

        
        //OPTIMIZE FUNCTION
        // checkScreenUpdate(event);

        
        ReleaseMutex(Mutex);
    }   
}


DWORD checkKeyboard(void *arg)
{
    Room * map = (Room*) arg;
    
    while(1)
    {
        MapData * event = peek(&map->stackEvents);
        WaitForSingleObject(Mutex, INFINITE);


        if(!map->screenModes.Fight)
        {
            checkEnemy(map);

            checkMove(map,event);

            checkHole(map);
        }
        else
        {
            selectOption(map);
        }


        ReleaseMutex(Mutex);
    }
}


#endif //PRESETTHREAD_H